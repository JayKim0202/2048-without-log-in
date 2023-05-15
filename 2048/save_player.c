#include "save_player.h"

int fread_playerNum() {
	FILE* fp;

	int numOfPlayers = 0;

	fp = fopen("players.txt", "r");

	if (fp == NULL) {
		return numOfPlayers;
	}

	char line[10000];
	char* lastLine = NULL;

	while (fgets(line, sizeof(line), fp) != NULL) {
		lastLine = _strdup(line);
		memset(line, 0, sizeof(line));
	}


	if (lastLine == NULL) {
		//printf("Empty file.\n");
		return numOfPlayers;
	}

	char* lastWord = NULL;
	char* delimiter = strrchr(lastLine, ':'); // Assuming ':' is the delimiter
	if (delimiter != NULL) {
		lastWord = _strdup(delimiter + 1); // Skip the delimiter and extract the word
	}

	numOfPlayers = atoi(lastWord);
	free(lastLine);
	free(lastWord);

	fclose(fp);

	return numOfPlayers + 1;
}

void fwrite_score(int score) {
	int numOfPlayers = fread_playerNum();

	FILE* fp;
	fp = fopen("players.txt", "a");
	if (fp == NULL) {
		//printf("Error opening file.\n");
		return; // Or handle the error as needed
	}

	// Convert the integers to strings
	char* scoreStr = calloc(20000, sizeof(char));
	char* numOfPlayersStr = calloc(10000, sizeof(char));
	sprintf(scoreStr, "%d", score);
	sprintf(numOfPlayersStr, "%d", numOfPlayers);

	// Calculate the required size for content and allocate memory
	size_t contentSize = strlen(scoreStr) + strlen(numOfPlayersStr) + 3; // 3 for ':' and '\n'
	char* content = calloc((contentSize + 1), sizeof(char)); // +1 for null terminator

	// Concatenate the strings
	snprintf(content, contentSize + 1, "%s:%s\n", scoreStr, numOfPlayersStr);

	// Use the concatenated string as needed
	//printf("Content: %s\n", content);

	fprintf(fp, "%s", content); // Append the content to the file


	// Free dynamically allocated memory
	free(scoreStr);
	free(numOfPlayersStr);
	free(content);

	fclose(fp); // Close the file
}

Player* fread_allPlayers() {
	int numOfPlayers = fread_playerNum();

	FILE* fp;
	Player* player = calloc(numOfPlayers, sizeof(Player));

	fp = fopen("players.txt", "r");
	if (fp == NULL) {
		return player; // Or handle the error as needed
	}

	char line[10000];
	char* lastLine = NULL;

	int i = 0;
	while (fgets(line, sizeof(line), fp) != NULL) {
		lastLine = _strdup(line);
		memset(line, 0, sizeof(line));


		char* lastWord = NULL;
		char* delimiter = strrchr(lastLine, ':'); // Assuming ':' is the delimiter
		if (delimiter != NULL) {
			*delimiter = '\0'; // Replace ':' with null terminator
			lastWord = _strdup(lastLine); // Extract the word before ':'
			player[i].score = atoi(lastWord);
			free(lastWord);

			lastWord = _strdup(delimiter + 1); // Extract the word after ':'
			player[i].playerNum = atoi(lastWord);
			free(lastWord);
		}
		free(lastLine);

		i++;
	}

	return player;
}

