open Yojson.Basic.Util

(* Define a record type for nodes *)
type node = {
  id: int;
  label: string;
  properties: (string * Yojson.Basic.t) list
}

(* Define a record type for edges *)
type edge = {
  source: int;
  target: int;
  typ: string
}

(* Function to parse nodes from JSON *)
let parse_nodes json =
  json |> member "nodes" |> to_list |> List.map (fun node_json ->
    {
      id = node_json |> member "id" |> to_int;
      label = node_json |> member "label" |> to_string;
      properties = node_json |> member "properties" |> to_assoc
    }
  )

(* Function to parse edges from JSON *)
let parse_edges json =
  json |> member "relationships" |> to_list |> List.map (fun edge_json ->
    {
      source = edge_json |> member "source" |> to_int;
      target = edge_json |> member "target" |> to_int;
      typ = edge_json |> member "type" |> to_string
    }
  )

(* Function to display nodes in a tabular format *)
let display_nodes nodes =
  print_endline "*****************************";
  print_endline "Nodes:";
  List.iter (fun node ->
    Printf.printf "ID: %d, Label: %s, Properties: " node.id node.label;
    List.iter (fun (key, value) ->
      Printf.printf "%s: %s, " key (Yojson.Basic.to_string value)
    ) node.properties;
    print_newline ();
    print_endline "---------------------------"
  ) nodes;
  print_endline "*****************************"

(* Function to display edges in a tabular format *)
let display_edges edges =
  print_endline "Edges:";
  List.iter (fun edge ->
    Printf.printf "Source: %d, Target: %d, Type: %s\n" edge.source edge.target edge.typ;
    print_endline "---------------------------"
  ) edges;
  print_endline "*****************************"

(* Function to compute and display statistics for integer properties *)
let display_statistics nodes =
  print_endline "Statistics:";
  let sums = Hashtbl.create 10 in
  let counts = Hashtbl.create 10 in

  List.iter (fun node ->
    List.iter (fun (key, value) ->
      match value with
      | `Int i ->
        Hashtbl.replace sums key (i + (try Hashtbl.find sums key with Not_found -> 0));
        Hashtbl.replace counts key ((try Hashtbl.find counts key with Not_found -> 0) + 1)
      | _ -> ()
    ) node.properties
  ) nodes;
  Hashtbl.iter (fun key sum ->
    let count = Hashtbl.find counts key in
    Printf.printf "Average %s: %f\n" key (float_of_int sum /. float_of_int count)
  ) sums;
  print_endline "*****************************"

(* Main function *)
let () =
  let filename = "../../data/response.json" in
  let json = Yojson.Basic.from_file filename in
  let nodes = parse_nodes json in
  let edges = parse_edges json in
  display_nodes nodes;
  display_edges edges;
  display_statistics nodes
