// Дан неориентированный граф.Выяснить, является ли граф связным.
#include <iostream>
#include <map>
#include <list>
#include <fstream>
#include <vector>

using namespace std;

ifstream in("unoriented.txt");

map<int, list<int>> graph(bool oriented) { //создание списка смежности графа
    map<int, list<int>> res;
    int x, y;
    while (in.peek() != EOF) {
        in >> x >> y; // вводим ребро в виде x -> y
        auto it_x = res.find(x);
        bool fl = true;
        if (it_x != res.end()) {
            for (auto it_y = it_x->second.begin();
                it_y != it_x->second.end(); it_y++)
                if (it_x->first == y) {
                    fl = false;
                    break;
                }
        }
        if (oriented) { // если граф ориентированный
            if (fl) {
                res[x].push_back(y);
                if (res.find(y) == res.end()) {
                    res[y].push_back(0);
                    auto it = res.find(y);
                    it->second.erase(it->second.begin());
                }
            }
        }
        else if (fl) { // если граф неориентированный
            res[x].push_back(y);
            res[y].push_back(x);
        }
    }
    return res;
}

void print(map <int, list<int>> Graph) { // вывод списка смежности на экран
    for (auto it = Graph.begin(); it != Graph.end(); it++) {
        cout << "Вершина " << it->first << ": ";
        list<int> a = it->second;
        for (auto iter = a.begin(); iter != a.end(); iter++)
            cout << *iter << " ";
        cout << endl;
    }
}

void DFS(map<int, list<int>> Graph, int x, vector <bool>& used) { // обход в глубину
    used[x] = true;
    for (auto it = Graph.begin(); it != Graph.end(); it++) {
        if (it->first == x) {
            list<int> a = it->second;
            for (auto iter = a.begin(); iter != a.end(); iter++)
                if (!used[*iter])
                    DFS(Graph, *iter, used);
            break;
        }
    }
}

int main() {
    setlocale(LC_ALL, "RUS");
    map <int, list<int>> Graph = graph(0);
    print(Graph);

    vector<bool> used(Graph.size(), false);
    DFS(Graph, 0, used);

    //определяем, является ли граф связным
    for (auto it = Graph.begin(); it != Graph.end(); it++) {
        if (used[it->first] == 0) {
            cout << "\nГраф не является связным";
            return 0;
        }
    }
    cout << "\nГраф является связным";
}
