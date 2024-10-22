import csv
from collections import deque, defaultdict

def load_graph(edge_file, data_file):
    graph = defaultdict(list)
    famous_names = {}

    # Carregar arestas do arquivo fb_famososedges.txt
    with open(edge_file, 'r') as ef:
        for line in ef:
            node1, node2 = map(int, line.strip().split(','))
            graph[node1].append(node2)
            graph[node2].append(node1)  # Adicionando a aresta de volta para ser não direcionado

    # Carregar nomes dos famosos do arquivo data.txt
    with open(data_file, 'r', encoding='utf-8') as df:
        reader = csv.reader(df)
        for row in reader:
            famous_id = int(row[2])  # ID é o terceiro campo
            famous_name = row[1]  # Nome é o segundo campo
            famous_names[famous_id] = famous_name

    return graph, famous_names

def bfs(graph, start, goal):
    visited = set()
    queue = deque([(start, 0)])  # (nó atual, profundidade)

    while queue:
        current_node, steps = queue.popleft()

        if current_node == goal:
            return steps

        if current_node not in visited:
            visited.add(current_node)
            for neighbor in graph[current_node]:
                if neighbor not in visited:
                    queue.append((neighbor, steps + 1))

    return -1  # Retorna -1 se não houver conexão

def main():
    edge_file = 'fb_famososedges.txt'
    data_file = 'data.txt'
    
    graph, famous_names = load_graph(edge_file, data_file)

    # IDs a serem pesquisados
    start_id = 415
    goal_id = 416

    steps = bfs(graph, start_id, goal_id)

    if steps != -1:
        print(f'Nome do famoso (nó origem - {start_id}): {famous_names.get(start_id, "Desconhecido")}')
        print(f'Nome do famoso (nó de destino - {goal_id}): {famous_names.get(goal_id, "Desconhecido")}')
        print(f'Quantidade de passos (arestas) que os separam: {steps}')
    else:
        print(f'Não há conexão entre os famosos {start_id} e {goal_id}.')

if __name__ == '__main__':
    main()
