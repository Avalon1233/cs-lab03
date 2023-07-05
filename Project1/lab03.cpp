#include <iostream>
#include <vector>

using namespace std;

vector<double> input_numbers(size_t number_count) {
    vector<double> result(number_count);
    for (size_t i = 0; i < number_count; i++) {
        cin >> result[i];
    }
    return result;
}

void find_minmax(const vector<double>& numbers, double& min, double& max) {
    min = numbers[0];
    max = numbers[0];
    for (double x : numbers) {
        if (x < min) {
            min = x;
        }
        else if (x > max) {
            max = x;
        }
    }
}

vector<size_t> make_histogram(const vector<double>& numbers, size_t bin_count, size_t number_count) {
    vector<size_t> result(bin_count);

    double min, max;
    find_minmax(numbers, min, max);

    double bin_size = (max - min) / bin_count;

    for (size_t i = 0; i < number_count; i++) {
        bool found = false;
        for (size_t j = 0; (j < bin_count - 1) && !found; j++) {
            auto lo = min + j * bin_size;
            auto hi = min + (j + 1) * bin_size;
            if ((lo <= numbers[i]) && (numbers[i] < hi)) {
                result[j]++;
                found = true;
            }
        }
        if (!found) {
            result[bin_count - 1]++;
        }
    }
    return result;
}

void show_histogram_text(const vector<size_t>& bins) {

    const size_t SCREEN_WIDTH = 80;
    const size_t MAX_ASTERISK = SCREEN_WIDTH - 3 - 1;

    size_t max_count = 0;

    for (size_t bin : bins) {
        if (bin > max_count) {
            max_count = bin;
        }
    }

    const bool scaling_needed = max_count > MAX_ASTERISK;

    for (size_t bin : bins) {
        if (bin < 10) {
            cout << "  ";
        }
        else if (bin < 100) {
            cout << ' ';
        }
        cout << bin << "|";

        size_t height = bin;

        if (scaling_needed) {
            const double scaling_factor = static_cast<double>(MAX_ASTERISK) / max_count;
            height = (size_t)(bin * scaling_factor);
        }

        for (size_t i = 0; i < height; i++) {
            cout << '*';
        }
        cout << '\n';
    }

}

int main() {

    // Ввод данных

    size_t number_count;

    cerr << "Enter number count: ";
    cin >> number_count;

    cerr << "Enter numbers: \n";
    const auto numbers = input_numbers(number_count);

    size_t bin_count;

    cerr << "Enter bin count: ";
    cin >> bin_count;

    // Обработка данных

    const auto bins = make_histogram(numbers, bin_count, number_count);

    // Вывод данных

    show_histogram_text(bins);

    return 0;

}