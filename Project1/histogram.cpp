#include "histogram.h"

void find_minmax(const vector<double>& numbers, double& min, double& max) {
    if (numbers.size() != 0) {
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
}

void svg_begin(double width, double height) {
    cout << "<?xml version='1.0' encoding='UTF-8'?>\n";
    cout << "<svg ";
    cout << "width='" << width << "' ";
    cout << "height='" << height << "' ";
    cout << "viewBox='0 0 " << width << " " << height << "' ";
    cout << "xmlns='http://www.w3.org/2000/svg'>\n";
}

void svg_end() {
    cout << "</svg>\n";
}

void svg_text(double left, double baseline, string text) {
    cout << "<text x='" << left << "' y='" << baseline << "'>" << text << "</text>";
}

void svg_rect(double x, double y, double width, double height, string stroke, string fill) {
    cout << "<rect x='" << x << "' y='" << y << "' width='" << width << "' height='" << height << "' stroke='" << stroke << "' fill='" << fill << "'/>";
}

void show_histogram_svg(const vector<size_t>& bins, string column_color) {
    const size_t SCREEN_WIDTH = 40;
    const size_t MAX_ASTERISK = SCREEN_WIDTH - 5;

    const auto IMAGE_WIDTH = 400;
    const auto IMAGE_HEIGHT = 300;
    const auto TEXT_LEFT = 20;
    const auto TEXT_BASELINE = 20;
    const auto TEXT_WIDTH = 50;
    const auto BIN_HEIGHT = 30;
    const auto BLOCK_WIDTH = 10;

    size_t max_count = 0;

    for (size_t bin : bins) {
        if (bin > max_count) {
            max_count = bin;
        }
    }

    svg_begin(IMAGE_WIDTH, IMAGE_HEIGHT);

    double top = 0;

    svg_header(IMAGE_WIDTH, top + TEXT_BASELINE, "Histogram");
    top += TEXT_BASELINE + 10;

    // 5 вариант 

    for (size_t bin : bins) {

        double bin_width = BLOCK_WIDTH * bin;

        if (max_count > MAX_ASTERISK) {
            const double scaling_factor = static_cast<double>(MAX_ASTERISK) / max_count;
            bin_width = BLOCK_WIDTH * bin * scaling_factor;
        }

        auto colvo_prob = max_count * BLOCK_WIDTH - bin_width;

        svg_rect(TEXT_LEFT + colvo_prob, top, bin_width, BIN_HEIGHT, "red", column_color);
        svg_text(colvo_prob + bin_width + TEXT_LEFT * 2, top + TEXT_BASELINE, to_string(bin));

        top += BIN_HEIGHT;
    }
    svg_end();
}

bool check_color(string color) {
    if (color == "red") {
        return false;
    }
    else {
        return true;
    }
}

string input_color_svg() {
    string color;
    do {
        cerr << "Enter a column fill color: ";
        getline(cin >> ws, color);
        transform(color.begin(), color.end(), color.begin(), ::tolower);
        if (!check_color(color)) {
            cerr << "You entered red. Select another color.\n";
        }
    } while (!check_color(color));
    return color;
}

void svg_header(const size_t width, const size_t baseline, string text) {
    const auto SYMBOL_WIDTH = 7.5;
    double word_width = text.length() * SYMBOL_WIDTH;
    double x = (width - word_width) / 2;
    svg_text(x, baseline, text);
}