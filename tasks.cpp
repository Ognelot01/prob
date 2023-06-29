#include "tasks.h"


// Функция для генерации случайного графа
QVector<QVector<int>> generateRandomGraph(int minSize, int maxSize)
{
    int size = QRandomGenerator::global()->bounded(minSize, maxSize + 1);

    QVector<QVector<int>> graph(size, QVector<int>(size, 0));
    for (int i = 0; i < size; ++i)
    {
        for (int j = i + 1; j < size; ++j)
        {
            int edge = QRandomGenerator::global()->bounded(2); // 0 или 1
            graph[i][j] = graph[j][i] = edge;
        }
    }
    return graph;
}


// Функция для проверки корректности решения
bool isSolutionCorrect(const QVector<QVector<int>>& graph, const QVector<int>& userPath)
{
    int size = graph.size();
    if (proposedSolution.size() != size)
        return false;

    bool correct = true;
        for (int i = 0; i < graph.size(); ++i) {
            if (userPath[i] != i || graph[userPath[i]][userPath[(i + 1) % graph.size()]] == 0) {
                correct = false;
                break;
            }
        }
    return correct;
}




QVariantMap Task1() {
    QVariantMap task;
    int length = twoToRandomPower();
    std::vector<bool> functionValues = randomFunctionValues(length);
    QString answer = calc_sdnf(functionValues);
    task["text"] = QString("Постройте систему представителей двудольного графа: %1")
            .arg(vectorToString(functionValues));
    task["answer"] = answer;
    return task;
}


QVariantMap Task2() {
    QVariantMap task;
    int length = twoToRandomPower();
    std::vector<bool> functionValues = randomFunctionValues(length);
    QString answer = calc_sknf(functionValues);
    //qDebug() << answer;
    task["text"] = QString("Проверьте, является ли граф двудольным: %1")
            .arg(vectorToString(functionValues));
    task["answer"] = answer;
    return task;
}

QVariantMap Task3() {
    QVariantMap task;
    QVector<QVector<int>> graph = generateRandomGraph(4, 10);
    QString text = "Задан следующий граф:\n";
        for (const auto& row : graph)
        {
            for (int val : row)
            {
                text += QString::number(val) + ' ';
            }
            text += '\n';
        }
        text += "Найдите гамильтонов цикл в этом графе (укажите вершины через пробел).";
    task["text"] = text;

    task["answer"] = "need_check";
    return task;
}
