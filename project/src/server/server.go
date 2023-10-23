package main

import (
	"fmt"
	"net/http"
)

type Size interface {
	Size() int
}
type gnode struct {
	// value string;
	// size int;
	props map[string]string
}

func makeGnode() *gnode {
	return &gnode{props: map[string]string{}}
}
func (n *gnode) Put(key string, val string) {
	n.props[key] = val
}
func (n *gnode) String() string {
	return fmt.Sprintf("%v", n.props)
}

type Graph struct {
	nodes []*gnode
}

func makeGraph() *Graph {
	return &Graph{nodes: make([]*gnode, 0, 10)}
}
func (g *Graph) Append(n *gnode) {
	g.nodes = append(g.nodes, n)
}
func (g *Graph) String() string {
	return "graph"
}
func (g *Graph) Size() int {
	return len(g.nodes)
}
func (g *Graph) Sum() (int, error) {
	sum := 0
	for _, el := range g.nodes {
		sum += len(el.props)
	}
	return sum, nil
}
func (g *Graph) Psum(ch chan<- int) {
	sum := 0
	for _, el := range g.nodes {
		sum += len(el.props)
	}
	ch <- sum
}
func (g *Graph) Traverse(ch chan<- int) {
	defer close(ch)
	for _, el := range g.nodes {
		ch <- len(el.props)
	}
}
func (g *Graph) Traverse2(vals chan<- int, ixs chan<- int) {
	defer close(vals)
	defer close(ixs)
	for ix, el := range g.nodes {
		vals <- len(el.props)
		ixs <- ix
	}
}
func (g *Graph) Help(w http.ResponseWriter, r *http.Request) {
	fmt.Fprintf(w, "this is help")
}
func (g *Graph) Info(w http.ResponseWriter, r *http.Request) {
	fmt.Fprintf(w, "this is info")
}
func main() {
	n := makeGnode()
	// var g *gnode = ...
	n.Put("a", "1")
	fmt.Printf("%v\n", n)
	fmt.Printf("%T\n", n)
	g := makeGraph()
	g.Append(n)
	fmt.Printf("%v\n", g)
	fmt.Printf("graph.size = %d\n", g.Size())
	var g2 *Graph = nil
	var s Size = g2
	// fmt.Printf("graph.size = %d\n", s.Size())
	if s != nil {
		fmt.Printf("not null\n")
	}
	// ch := make(chan int)
	// go g.Psum(ch)
	// res := <- ch
	// fmt.Printf("sum = %v\n", res)
	// sum := 0
	// for v := range ch {
	// sum += v
	// }
	// fmt.Printf("sum = %v\n", sum)
	vals := make(chan int)
	ixs := make(chan int)
	go g.Traverse2(vals, ixs)
	for {
		var v int
		var ok bool
		select {
		case v, ok = <-vals:
		case v, ok = <-ixs:
		}
		if !ok {
			break
		}
		fmt.Printf("%v\n", v)
	}
	// http.HandleFunc("/help", g.Help)
	// http.HandleFunc("/info", g.Info)
	// http.ListenAndServe(":8080", nil)
	// sum, err := g.Sum()
	// if err != nil {
	// // ....
	// }
	// fmt.Printf("%v\n", sum)
}
