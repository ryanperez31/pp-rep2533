package main

import (
	"flag"
	"fmt"
	"log"
	"net/http"
	"strings"

	"github.com/neo4j/neo4j-go-driver/v4/neo4j"
)

var (
	NEO4J_URI      string
	NEO4J_USERNAME string
	NEO4J_PASSWORD string
)

// runQuery runs a query on the Neo4j database and returns the results.
func runQuery(query string) (string, error) {
	driver, err := neo4j.NewDriver(NEO4J_URI, neo4j.BasicAuth(NEO4J_USERNAME, NEO4J_PASSWORD, ""))
	if err != nil {
		return "", err
	}
	defer driver.Close()

	session := driver.NewSession(neo4j.SessionConfig{})
	defer session.Close()

	result, err := session.Run(query, map[string]interface{}{})
	if err != nil {
		return "", err
	}

	records, err := result.Collect()
	if err != nil {
		return "", err
	}

	var resultsStr []string
	for _, record := range records {
		for _, value := range record.Values {
			resultsStr = append(resultsStr, fmt.Sprint(value))
		}
	}

	return fmt.Sprintf("Query: %s\nResults: %s", query, strings.Join(resultsStr, ", ")), nil
}

func preselectedQueriesHandler(w http.ResponseWriter, r *http.Request) {
	// These are just example queries. Adjust them based on your Neo4j database schema and data.
	queries := []string{
		"MATCH (n) RETURN n LIMIT 5",
		"MATCH (n:Person) RETURN n.name LIMIT 5",
	}

	for _, query := range queries {
		result, err := runQuery(query)
		if err != nil {
			http.Error(w, err.Error(), http.StatusInternalServerError)
			return
		}
		fmt.Fprintf(w, "%s\n\n", result)
	}
}

func customQueryHandler(w http.ResponseWriter, r *http.Request) {
	query := r.URL.Query().Get("query")
	if query == "" {
		http.Error(w, "Query parameter is missing.", http.StatusBadRequest)
		return
	}

	result, err := runQuery(query)
	if err != nil {
		http.Error(w, err.Error(), http.StatusInternalServerError)
		return
	}

	fmt.Fprint(w, result)
}

func main() {
	flag.StringVar(&NEO4J_URI, "uri", "bolt://localhost:7687", "URI for the Neo4j database")
	flag.StringVar(&NEO4J_USERNAME, "username", "neo4j", "Username for the Neo4j database")
	flag.StringVar(&NEO4J_PASSWORD, "password", "", "Password for the Neo4j database")
	flag.Parse()

	if NEO4J_PASSWORD == "" {
		log.Fatal("Password must be provided.")
	}
	http.HandleFunc("/preselected-queries", preselectedQueriesHandler)
	http.HandleFunc("/custom-query", customQueryHandler)

	log.Fatal(http.ListenAndServe(":8080", nil))
}
