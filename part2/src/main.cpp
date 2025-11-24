#include <iostream>

#include <cstring>

using namespace std;

struct SystemRequirements {

    const char* system_name;

    int optimal_path_needed;

    int memory_limited;

    int speed_priority;

    int graph_has_weights;

    int use_heuristics;

    int graph_is_tree;

    int need_complete_search;

};

struct AlgorithmCandidate {

    const char* name;

    int optimality;

    int memory_usage;

    int speed;

    int handles_weights;

    int uses_heuristics;

    int tree_efficiency;

    int complete_search;

    const char* best_case;

    const char* worst_case;

};

void show_tree_help() {

    cout << endl << "=== СПРАВКА: ДЕРЕВО ИЛИ ГРАФ? ===" << endl;

    cout << "Дерево - это особый вид графа БЕЗ циклов и петель." << endl;

    cout << endl << "ГРАФ ЯВЛЯЕТСЯ ДЕРЕВОМ если:" << endl;

    cout << "- Есть один корень и ветви расходятся от него" << endl;

    cout << "- НЕТ циклов (нельзя вернуться в ту же точку)" << endl;

    cout << "- НЕТ петель (ребер из узла в самого себя)" << endl;

    cout << "- Между любыми двумя узлами только один путь" << endl;

    cout << endl << "ПРИМЕРЫ ДЕРЕВЬЕВ:" << endl;

    cout << "- Файловая система (папки и файлы)" << endl;

    cout << "- Организационная структура компании" << endl;

    cout << "- Генеалогическое древо" << endl;

    cout << "- Иерархия категорий товаров" << endl;

    cout << "- DOM-дерево веб-страницы" << endl;

    cout << endl << "ГРАФ НЕ ЯВЛЯЕТСЯ ДЕРЕВОМ если:" << endl;

    cout << "- Есть циклы (A->B->C->A)" << endl;

    cout << "- Есть несколько путей между узлами" << endl;

    cout << "- Сложные взаимосвязи" << endl;

    cout << endl << "ПРИМЕРЫ НЕ-ДЕРЕВЬЕВ:" << endl;

    cout << "- Дорожная сеть (много маршрутов)" << endl;

    cout << "- Социальная сеть (друзья друзей)" << endl;

    cout << "- Сеть метро (пересадки, кольца)" << endl;

    cout << "- Интернет (много связей между сайтами)" << endl;

    cout << endl << "ОПРЕДЕЛЕНИЕ: данные имеют иерархическую структуру (дерево) или сложную сеть (граф)?" << endl;

}

void show_heuristics_help() {

    cout << endl << "=== СПРАВКА: ИСПОЛЬЗОВАНИЕ ЭВРИСТИК ===" << endl;

    cout << "Эвристика - это правило для оценки расстояния до цели." << endl;

    cout << endl << "КОГДА МОЖНО ИСПОЛЬЗОВАТЬ эвристики:" << endl;

    cout << "- Есть информация о примерном расположении цели" << endl;

    cout << "- Можно оценить расстояние по прямой до цели" << endl;

    cout << "- Известны координаты в пространстве (геолокация)" << endl;

    cout << "- Есть метрика для оценки близости к цели" << endl;

    cout << endl << "ПРИМЕРЫ С ЭВРИСТИКАМИ:" << endl;

    cout << "- Навигатор: расстояние по прямой до точки назначения" << endl;

    cout << "- Игры: манхэттенское расстояние на сетке" << endl;

    cout << "- Поиск в соцсетях: количество общих друзей" << endl;

    cout << "- Рекомендации: схожесть интересов" << endl;

    cout << endl << "КОГДА НЕЛЬЗЯ ИСПОЛЬЗОВАТЬ эвристики:" << endl;

    cout << "- Нет информации о расположении цели" << endl;

    cout << "- Нельзя оценить расстояние до цели" << endl;

    cout << "- Все узлы равнозначны (нет метрики близости)" << endl;

    cout << "- Веб-краулинг (неизвестно где нужная страница)" << endl;

    cout << endl << "ОПРЕДЕЛЕНИЕ: можно ли оценить насколько узел близок к цели?" << endl;

}

void show_complete_search_help() {

    cout << endl << "=== СПРАВКА: ПОЛНЫЙ ОБХОД ГРАФА ===" << endl;

    cout << "Полный обход - это когда нужно посетить ВСЕ узлы графа." << endl;

    cout << endl << "КОГДА НУЖЕН полный обход:" << endl;

    cout << "- Поиск всех файлов в файловой системе" << endl;

    cout << "- Анализ зависимостей в коде (найти все связи)" << endl;

    cout << "- Сбор статистики по всей сети" << endl;

    cout << "- Поиск циклических зависимостей" << endl;

    cout << "- Веб-краулинг (обход всех страниц сайта)" << endl;

    cout << "- Поиск неизвестного элемента" << endl;

    cout << endl << "КОГДА НЕ НУЖЕН полный обход:" << endl;

    cout << "- Найти кратчайший путь из точки A в точку B" << endl;

    cout << "- Поиск конкретного известного элемента" << endl;

    cout << "- Маршрутизация (только до цели)" << endl;

    cout << "- Навигация (построение маршрута)" << endl;

    cout << "- Поиск игрока в онлайн-игре" << endl;

    cout << endl << "ОПРЕДЕЛЕНИЕ: нужно ли посещать ВСЕ узлы или только найти путь к ЦЕЛИ?" << endl;

}

void compare_for_system(SystemRequirements system, AlgorithmCandidate algorithms[], int count) {

    cout << "=== СИСТЕМА: " << system.system_name << " ===" << endl;

    cout << "Требования: оптимальность=" << system.optimal_path_needed << "/10, память=" << system.memory_limited << "/10, скорость=" << system.speed_priority << "/10" << endl;

    cout << "Веса: " << (system.graph_has_weights ? "да" : "нет") << ", Эвристики: " << (system.use_heuristics ? "да" : "нет") << ", Дерево: " << (system.graph_is_tree ? "да" : "нет") << ", Полный обход: " << (system.need_complete_search ? "да" : "нет") << endl;

    int scores[5] = {0};

    for (int i = 0; i < count; i++) {

        int score = 0;

        score += algorithms[i].optimality * system.optimal_path_needed;

        score += (10 - algorithms[i].memory_usage) * system.memory_limited;

        score += algorithms[i].speed * system.speed_priority;

        if (system.graph_has_weights && algorithms[i].handles_weights)

            score += 25;

        if (system.use_heuristics && algorithms[i].uses_heuristics)

            score += 20;

        if (system.graph_is_tree)

            score += algorithms[i].tree_efficiency * 2;

        if (system.need_complete_search)

            score += algorithms[i].complete_search * 3;

        scores[i] = score;

        cout << algorithms[i].name << ": " << score << " баллов" << endl;

    }

    cout << "ТОП-3 АЛГОРИТМА:" << endl;

    for (int place = 1; place <= 3; place++) {

        int max_score = -1;

        int max_index = -1;

        const char* place_symbol = "";

        if (place == 1) place_symbol = "I";

        else if (place == 2) place_symbol = "II";

        else place_symbol = "III";

        for (int i = 0; i < count; i++) {

            if (scores[i] > max_score) {

                max_score = scores[i];

                max_index = i;

            }

        }

        if (max_index != -1) {

            cout << place_symbol << " место: " << algorithms[max_index].name << " (" << max_score << " баллов)" << endl;

            scores[max_index] = -1;

        }

    }

    cout << "=========================================" << endl;

}

void input_system_requirements(SystemRequirements &system, const char* system_name) {

    system.system_name = system_name;

    cout << "=== ОЦЕНКА СИСТЕМЫ: " << system_name << " ===" << endl;

    cout << "Оцените требования вашей системы по шкале от 1 до 10:" << endl;

    cout << "Насколько важен оптимальный путь? (1-не важен, 10-критически важен): ";

    cin >> system.optimal_path_needed;

    cout << "Насколько ограничена память? (1-не ограничена, 10-сильно ограничена): ";

    cin >> system.memory_limited;

    cout << "Насколько важна скорость поиска? (1-не важна, 10-критически важна): ";

    cin >> system.speed_priority;

    cout << "Есть ли веса у ребер графа? (0-нет, 1-да): ";

    cin >> system.graph_has_weights;



    char help_choice;

    cout << "Следующий вопрос касается использования эвристик. Показать справку по использованию эвристик? (y-да, n-нет): ";

    cin >> help_choice;

    if (help_choice == 'y' || help_choice == 'Y') {

        show_heuristics_help();

    }

    cout << "Можно ли использовать эвристики? (0-нет, 1-да): ";

    cin >> system.use_heuristics;



    cout << ". Следующий вопрос касается уточнения является ли Ваша структура деревом. Показать справку по определению типа графа (дерево/не дерево)? (y-да, n-нет): ";

    cin >> help_choice;

    if (help_choice == 'y' || help_choice == 'Y') {

        show_tree_help();

    }

    cout << "Граф является деревом? (0-нет, 1-да): ";

    cin >> system.graph_is_tree;



    cout << " Следующий вопрос касается необходимости полного обхода графа.  Показать справку по полному обходу графа? (y-да, n-нет): ";

    cin >> help_choice;

    if (help_choice == 'y' || help_choice == 'Y') {

        show_complete_search_help();

    }

    cout << "Нужен ли полный обход графа? (0-нет, 1-да): ";

    cin >> system.need_complete_search;

}

int main() {

    cout << "=== Выбор алгоритма поиска ===" << endl;

    AlgorithmCandidate algorithms[] = {

        {"DFS", 2, 3, 8, 0, 0, 10, 10, "Деревья, полный обход", "Взвешенные графы"},

        {"BFS", 8, 8, 7, 0, 0, 8, 8, "Кратчайший путь без весов", "Большие графы"},

        {"Greedy BFS", 3, 4, 9, 0, 1, 7, 3, "Быстрый поиск с эвристикой", "Требуется оптимальность"},

        {"Greedy DFS", 2, 3, 8, 0, 1, 9, 6, "Локальная оптимизация", "Комплексные пути"},

        {"A*", 10, 6, 7, 1, 1, 6, 4, "Оптимальные пути с эвристикой", "Нет эвристики"}

    };

    cout << "Выберите тип системы для анализа:" << endl;

    cout << "1. Навигатор такси" << endl;

    cout << "2. Веб-краулер" << endl;

    cout << "3. ИИ для шахмат" << endl;

    cout << "4. Сетевой анализ" << endl;

    cout << "5. Рекомендательная система" << endl;

    cout << "6. Социальный граф (друзья)" << endl;

    int choice;

    cout << "Ваш выбор (1-6): ";

    cin >> choice;

    SystemRequirements selected_system;

    const char* system_names[] = {

        "Навигатор такси", "Веб-краулер", "ИИ для шахмат",

        "Сетевой анализ", "Рекомендательная система", "Социальный граф (друзья)"

    };

    if (choice >= 1 && choice <= 6) {

        input_system_requirements(selected_system, system_names[choice - 1]);

    } else {

        cout << "Неверный выбор!" << endl;

        return 1;

    }

    int num_algorithms = sizeof(algorithms) / sizeof(algorithms[0]);

    compare_for_system(selected_system, algorithms, num_algorithms);

    cout << "=== ОБЪЯСНЕНИЕ РЕЗУЛЬТАТОВ ===" << endl;

    cout << "- DFS: лучший для деревьев и полного обхода, минимальная память" << endl;

    cout << "- BFS: гарантирует кратчайший путь в невзвешенных графах" << endl;

    cout << "- Greedy BFS: скорость с эвристикой, но без гарантий оптимальности" << endl;

    cout << "- Greedy DFS: локальная оптимизация с малой памятью" << endl;

    cout << "- A*: лучший для оптимальных путей с эвристикой" << endl;

    return 0;

}
