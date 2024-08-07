#include <stdio.h>
#include <stdint.h>

int main() {
	FILE *file = fopen("puzzles/output.bin", "rb");
	if (file == NULL) {
		perror("Error opening file");
		return 1;
	}

	uint8_t rows;
	uint8_t cols;
	size_t rows_read = fread(&rows, sizeof(uint8_t), 1, file);
	size_t cols_read = fread(&cols, sizeof(uint8_t), 1, file);
	if (rows_read != 1 || cols_read != 1) {
		perror("Error reading from file");
		fclose(file);
		return 1;
	}

	fclose(file);

	printf("Rows read from file: %u\n", rows);
	printf("Cols read from file: %u\n", cols);

	return 0;
}
