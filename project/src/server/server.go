package main

import (
	"fmt"
	"log"
	"net/http"
	"strings"

	"github.com/neo4j/neo4j-go-driver/v4/neo4j"
)

const (
	NEO4J_URI      = "bolt://localhost:7687"
	NEO4J_USERNAME = "neo4j"
	NEO4J_PASSWORD = "31chargers"
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
	http.HandleFunc("/preselected-queries", preselectedQueriesHandler)
	http.HandleFunc("/custom-query", customQueryHandler)

	log.Fatal(http.ListenAndServe(":8080", nil))
}
