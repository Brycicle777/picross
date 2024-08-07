#include <stdio.h>
#include <stdint.h>

int main() {
	//255 max for each value
	int rows, cols;
	rows = 10;
	cols = 5;
	uint8_t brows = (uint8_t)rows;
	uint8_t bcols = (uint8_t)cols;

	FILE *file = fopen("puzzles/output.bin", "wb");
	if (file == NULL) {
		perror("Error opening file");
		return 1;
	}

	size_t row_bytes_written = fwrite(&brows, sizeof(uint8_t), 1, file);
	size_t col_bytes_written = fwrite(&bcols, sizeof(uint8_t), 1, file);
	if (row_bytes_written != 1 || col_bytes_written != 1) {
		perror("Error writing to file");
		fclose(file);
		return 1;
	}

	fclose(file);

	printf("Data written to file successfully.\n");
	return 0;
}
