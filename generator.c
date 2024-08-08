#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>

int main() {
	//255 max for each value
	uint8_t rows = (uint8_t)5;
	uint8_t cols = (uint8_t)5;
	char *puzzle =	"01110"
			"10111"
			"11111"
			"11101"
			"01110";
	char puzzle_name[] = "button";

	char file_name[100] = "puzzles/";
	strcat(file_name, puzzle_name);
	strcat(file_name, ".bin");

	FILE *file = fopen(file_name, "wb");
	if (file == NULL) {
		perror("Error opening file");
		return 1;
	}

	size_t row_bytes_written = fwrite(&rows, sizeof(uint8_t), 1, file);
	size_t col_bytes_written = fwrite(&cols, sizeof(uint8_t), 1, file);
	if (row_bytes_written != 1 || col_bytes_written != 1) {
		perror("Error writing puzzle headers to file");
		fclose(file);
		return 1;
	}

	size_t puzzle_bytes_written = 0;
	unsigned char byte = 0;
	int length = strlen(puzzle);

	for (int i = 0; i < length; i++) {
		if (puzzle[i] == '1') {
			byte |= (1 << (length - 1 - i));
		}
		if ((i + 1) % 8 == 0) {
			puzzle_bytes_written += fwrite(&byte, sizeof(byte), 1, file);
			byte = 0;
		}
		if (i == length - 2) {
			puzzle_bytes_written += fwrite(&byte, sizeof(byte), 1, file);
		}
	}
	if (puzzle_bytes_written != length / 8 + 1) {
		perror("Error writing puzzle data to file");
		fclose(file);
		return 1;
	}

	fclose(file);

	printf("Data written to file successfully.\n");
	return 0;
}
