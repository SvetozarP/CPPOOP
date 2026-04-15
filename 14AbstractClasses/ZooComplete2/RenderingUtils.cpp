#include "RenderingUtils.h"
#include "ConsoleUtils.h"

Renderer::Renderer(int size) : size(size) {
	for (int r = 0; r < size; r++) {
		std::vector<char> bufferRow;
		for (int c = 0; c < size; c++) {
			bufferRow.push_back(' ');
		}
		renderBuffer.push_back(bufferRow);
	}
}

void Renderer::render(Position p, std::string image) {
	for (int i = 0; i < image.size() && p.getCol() + i < size; i++) {
		renderBuffer[p.getRow()][p.getCol() + i] = image[i];
	}
}

void Renderer::flushToScreen() {
	std::ostringstream output;
	for (int r = 0; r < size; r++) {
		for (int c = 0; c < size; c++) {
			output << this->renderBuffer[r][c];
			this->renderBuffer[r][c] = ' ';
		}
		output << std::endl;
	}

	clearScreen();
	std::cout << output.str() << std::endl;
}
