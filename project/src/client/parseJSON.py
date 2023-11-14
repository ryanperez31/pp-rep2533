import json
import re

def parse_and_convert_to_json(text_file, json_file):
    with open(text_file, 'r') as file:
        content = file.read()

    # Regex pattern to extract nodes and relationships
    node_pattern = r'\{(\d+) \[([^\]]+)\] map\[(.*?)\]\}'
    relationship_pattern = r'\{(\d+) (\d+) (\d+) ([^\s]+) map\[(.*?)\]\}'

    nodes = []
    relationships = []

    # Extract and process nodes
    for match in re.findall(node_pattern, content):
        node_id, label, properties_str = match
        properties = parse_properties(properties_str)
        nodes.append({
            "id": int(node_id),
            "label": label,
            "properties": properties
        })

    # Extract and process relationships
    for match in re.findall(relationship_pattern, content):
        start_node, _, end_node, rel_type, properties_str = match
        properties = parse_properties(properties_str)
        relationships.append({
            "source": int(start_node),
            "target": int(end_node),
            "type": rel_type,
            "properties": properties
        })

    graph = {
        "nodes": nodes,
        "relationships": relationships
    }

    with open(json_file, 'w') as file:
        json.dump(graph, file, indent=4)

def parse_properties(properties_str):
    properties = {}
    if properties_str:
        # Split properties string into key-value pairs
        prop_pairs = re.split(r', (?=\w+:)', properties_str)
        for pair in prop_pairs:
            if ':' in pair:
                key, value = pair.split(':', 1)
                key = key.strip()
                value = value.strip()
                # Attempt to convert numerical values
                try:
                    value = int(value)
                except ValueError:
                    try:
                        value = float(value)
                    except ValueError:
                        pass  # Leave value as string if conversion fails
                properties[key] = value
    return properties

if __name__ == "__main__":
    parse_and_convert_to_json('../data/response.txt', '../data/response.json')
