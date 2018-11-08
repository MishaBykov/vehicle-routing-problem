from typing import List

a = open('Taxicab_100.txt')
tax_lines: List[str] = a.readlines()
a.close()
n = int(tax_lines[0])
points = []
for i in range(1, n):
    points.append(tax_lines[i].split())
a = open('result1.txt')
results = []
for i in range(0, 5):
    results.append({})
    asd = a.readline()
    results[i]['cost'] = int(asd)
    results[i]['ind'] = a.readline().split()
    p = a.readline().split()
    a.readline()
    results[i]['points'] = []
    for j in range(0, len(p), 2):
        results[i]['points'].append([[int(p[j])], [int(p[j + 1])]])
a.close()
for i in range(0, 5):
    results[i]['points_sort'] = []
    for j in results[i]['ind']:
        results[i]['points_sort'].append(results[i]['points'][int(results[i]['ind'][int(j)])])
for i in range(0, 5):
    results[i]['ind_points'] = []
    for j in results[i]['points_sort']:
        for k in range(0, len(points)):
            if j[0][0] == int(points[k][0]) and j[1][0] == int(points[k][1]):
                results[i]['ind_points'].append(k + 1)
max_cost = 0
sum_cost = 0
for i in range(0, 5):
    sum_cost += results[i]['cost']
    if results[i]['cost'] > max_cost:
        max_cost = results[i]['cost']
    print('Маршрут ' + str(i+1) + ' : ' + str(len(results[i]['ind_points'])) + ' вершин')
    for j in results[i]['ind_points']:
        print(str(j) + ' ', end="")
    print()
    print("Вес маршрута: " + str(results[i]['cost']))
print('Суммарный вес всех маршрутов: ' + str(sum_cost))
