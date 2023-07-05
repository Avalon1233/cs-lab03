#include "histogram.h"

vector<double> input_numbers(size_t number_count) {
    vector<double> result(number_count);
    for (size_t i = 0; i < number_count; i++) {
        cin >> result[i];
    }
    return result;
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

    show_histogram_svg(bins);

    return 0;

}