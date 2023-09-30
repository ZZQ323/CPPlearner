#include <iostream>
#include <vector>
#include <cmath>
#include <random>
#include <algorithm>

using namespace std;

//控制信息素的重要性
const double ALPHA = 1.0;
//控制距离的重要性
const double BETA = 2.0;
//信息素所有多少比例挥发，即留存（1-RHO）
const double RHO = 0.5;
//信息素增加强度
const double Q = 100.0;

const int city_num = 50;
const int ant_num = 50;

//城市x坐标
vector<int> distance_x = {
    178, 272, 176, 171, 650, 499, 267, 703, 408, 437, 491, 74, 532,
    416, 626, 42, 271, 359, 163, 508, 229, 576, 147, 560, 35, 714,
    757, 517, 64, 314, 675, 690, 391, 628, 87, 240, 705, 699, 258,
    428, 614, 36, 360, 482, 666, 597, 209, 201, 492, 294
};

//城市y坐标
vector<int> distance_y = {
    170, 395, 198, 151, 242, 556, 57, 401, 305, 421, 267, 105, 525,
    381, 244, 330, 395, 169, 141, 380, 153, 442, 528, 329, 232, 48,
    498, 265, 343, 120, 165, 50, 433, 63, 491, 275, 348, 222, 288,
    490, 213, 524, 244, 114, 104, 552, 70, 425, 227, 331
};

//路径长度
vector<vector<double>> distance_graph(city_num, vector<double>(city_num, 0.0));
//信息素图
vector<vector<double>> pheromone_graph(city_num, vector<double>(city_num, 1.0));

class Ant {
private:
    int ID;
    vector<int> path;
    double total_distance;

    // 走了多少步，但是没给用上过
    int move_count;
    int current_city;
    vector<bool> open_table_city;

public:
    Ant(int id) :   
        ID(id), total_distance(0.0), move_count(0), 
        current_city(-1), open_table_city(city_num, true) {
        // 随机空降在一个城市
        int city_index = rand() % city_num;
        // 现在所处的城市位置
        current_city = city_index;
        // 城市选择
        path.push_back(city_index);
        // 还没有被选择的城市
        open_table_city[city_index] = false;
        // 移动次数
        move_count = 1;
    }

    void choice_next_city() {
        int next_city = -1;
        // 选择城市i的概率
        vector<double> select_citys_prob(city_num, 0.0);
        double total_prob = 0.0;

        for (int i = 0; i < city_num; ++i) {
            if (open_table_city[i]) {
                try {
                    select_citys_prob[i] = 
                        pow(pheromone_graph[current_city][i], ALPHA) *
                        pow(1.0 / distance_graph[current_city][i], BETA);
                    total_prob += select_citys_prob[i];
                }catch(const exception& e) {
                    cerr << "Ant ID: " << ID << ", current city: "
                        << current_city << ", target city: " << i << endl;
                    exit(1);
                }
            }
        }

        if (total_prob > 0.0) {
            uniform_real_distribution<double> dis(0.0,total_prob);
            mt19937 rng(random_device());
            double temp_prob =dis(rng);
            for (int i = 0; i < city_num; ++i) {
                if (open_table_city[i]) {
                    temp_prob -= select_citys_prob[i];
                    if (temp_prob < 0.0) {
                        next_city = i;
                        break;
                    }
                }
            }
        }

        if (next_city == -1) {
            //  随机选择下一个城市的ID
            next_city = rand() % city_num;
            while (!open_table_city[next_city]) {
                next_city = rand() % city_num;
            }
        }

        current_city = next_city;
        path.push_back(next_city);
        open_table_city[next_city] = false;
        total_distance += distance_graph[current_city][next_city];
        move_count++;
    }

    // 计算当前路径总长度
    void cal_total_distance() {
        double temp_distance = 0.0;

        for (int i = 1; i < city_num; ++i) {
            int start = path[i];
            int end = path[i - 1];
            temp_distance += distance_graph[start][end];
        }

        total_distance = temp_distance;
    }

    void reset() {
        path.clear();
        total_distance = 0.0;
        move_count = 0;
        current_city = -1;
        fill(open_table_city.begin(), open_table_city.end(), true);
        
        // 重复构造函数那一步
        int city_index = rand() % city_num;
        current_city = city_index;
        path.push_back(city_index);
        open_table_city[city_index] = false;
        move_count = 1;
    }

    int get_id() const {
        return ID;
    }

    const vector<int>& get_path() const {
        return path;
    }

    double get_total_distance() const {
        return total_distance;
    }
};

// 处理出任意两个城市之间的距离
void calculate_distance_graph() 
{
    for (int i = 0; i < city_num; ++i) {
        for (int j = 0; j < city_num; ++j) {
            int x = distance_x[i] - distance_x[j];
            int y = distance_y[i] - distance_y[j];
            distance_graph[i][j] = sqrt(x * x + y * y);
        }
    }
}

void ant_colony_tsp() 
{
    vector<Ant> ants(ant_num, Ant(0));
    Ant best_ant(0);
    calculate_distance_graph();

    for (int i = 0; i < 500; ++i) {
        for (int j = 0; j < ant_num; ++j) {
            for (int k = 1; k < city_num; ++k) {
                ants[j].choice_next_city();
            }

            ants[j].cal_total_distance();

            if (ants[j].get_total_distance() < best_ant.get_total_distance() 
                || best_ant.get_total_distance() == 0.0) {
                best_ant = ants[j];
            }

            ants[j].reset();
        }

        // Update pheromone graph
        for (int j = 0; j < city_num; ++j) {
            for (int k = 0; k < city_num; ++k) {
                pheromone_graph[j][k] *= (1.0 - RHO);
            }
        }

        for (int j = 1; j < city_num; ++j) {
            int start = best_ant.get_path()[j];
            int end = best_ant.get_path()[j - 1];
            pheromone_graph[start][end] += (Q / best_ant.get_total_distance());
            pheromone_graph[end][start] = pheromone_graph[start][end];
        }
    }

    cout << "Best Path: ";
    for (int i = 0; i < city_num; ++i) {
        cout << best_ant.get_path()[i] << " ";
    }
    cout << endl;

    cout << "Best Distance: " << best_ant.get_total_distance() << endl;
}

int main() {
    ant_colony_tsp();
    return 0;
}