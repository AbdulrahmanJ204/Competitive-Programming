#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <string>
#include <set>

using namespace std;

// Structure to hold the rectangle's dimensions and name
struct Rectangle {
    int width;
    int height;
    string name;
};

int calculate_total_area(const vector<Rectangle>& rectangles) {
    int total_area = 0;
    for (const auto& rect : rectangles) {
        total_area += rect.width * rect.height;
    }
    return total_area;
}

vector<pair<int, int>> find_possible_dimensions(int total_area) {
    vector<pair<int, int>> possible_dimensions;
    for (int width = 1; width * width <= total_area; ++width) {
        if (total_area % width == 0) {
            int height = total_area / width;
            possible_dimensions.push_back({width, height});
            if (width != height) {
                possible_dimensions.push_back({height, width});
            }
        }
    }
    return possible_dimensions;
}

bool can_place_rectangle(vector<vector<string>>& grid, int x, int y, int rect_width, int rect_height) {
    for (int i = 0; i < rect_height; ++i) {
        for (int j = 0; j < rect_width; ++j) {
            if (x + i >= grid.size() || y + j >= grid[0].size() || !grid[x + i][y + j].empty()) {
                return false;
            }
        }
    }
    return true;
}

void place_rectangle(vector<vector<string>>& grid, int x, int y, int rect_width, int rect_height, const string& rect_name) {
    for (int i = 0; i < rect_height; ++i) {
        for (int j = 0; j < rect_width; ++j) {
            grid[x + i][y + j] = rect_name;
        }
    }
}

void remove_rectangle(vector<vector<string>>& grid, int x, int y, int rect_width, int rect_height) {
    for (int i = 0; i < rect_height; ++i) {
        for (int j = 0; j < rect_width; ++j) {
            grid[x + i][y + j] = "";
        }
    }
}

string grid_to_string(const vector<vector<string>>& grid) {
    string result;
    for (const auto& row : grid) {
        for (const auto& cell : row) {
            result += cell.empty() ? '.' : cell[0];
        }
        result += '\n';
    }
    return result;
}

bool backtrack(vector<Rectangle>& rectangles, vector<vector<string>>& grid, int index, set<string>& unique_configs) {
    if (index == rectangles.size()) {
        unique_configs.insert(grid_to_string(grid));
        return true;
    }

    int rect_width = rectangles[index].width;
    int rect_height = rectangles[index].height;
    string rect_name = rectangles[index].name;

    bool found = false;
    for (int i = 0; i < grid.size(); ++i) {
        for (int j = 0; j < grid[0].size(); ++j) {
            if (can_place_rectangle(grid, i, j, rect_width, rect_height)) {
                place_rectangle(grid, i, j, rect_width, rect_height, rect_name);
                if (backtrack(rectangles, grid, index + 1, unique_configs)) found = true;
                remove_rectangle(grid, i, j, rect_width, rect_height);
            }
            if (can_place_rectangle(grid, i, j, rect_height, rect_width)) {
                place_rectangle(grid, i, j, rect_height, rect_width, rect_name);
                if (backtrack(rectangles, grid, index + 1, unique_configs)) found = true;
                remove_rectangle(grid, i, j, rect_height, rect_width);
            }
        }
    }

    return found;
}

int counter(vector<Rectangle>& rectangles) {
    int total_area = calculate_total_area(rectangles);
    vector<pair<int, int>> possible_dimensions = find_possible_dimensions(total_area);

    sort(rectangles.begin(), rectangles.end(), [](const Rectangle& a, const Rectangle& b) {
        return (a.width * a.height) > (b.width * b.height);
    });

    set<string> unique_configs;
    for (const auto& dim : possible_dimensions) {
        vector<vector<string>> grid(dim.second, vector<string>(dim.first, ""));
        backtrack(rectangles, grid, 0, unique_configs);
    }
    return unique_configs.size();
}

int main() {
    vector<Rectangle> rectangles = {
            {10, 5, "A"}
            ,{10, 5, "B"}
            ,{15, 10, "C"}

    };

    int count = counter(rectangles);
    cout << "Number of unique ways to form the rectangle: " << count << endl;

    return 0;
}