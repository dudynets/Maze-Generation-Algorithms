#include "helpers.h"

// Random number generator.
unsigned int randomGenerator() {
  // Create a Mersenne Twister random number generator seeded with current time.
  mt19937 gen(std::chrono::system_clock::now().time_since_epoch().count());

  // Create a uniform distribution to generate integers between 0 and RAND_MAX.
  uniform_int_distribution<int> dist(0, RAND_MAX);

  // Return a random number.
  return dist(gen);
}

// Function that colors the string.
string colorString(
    const string& str,
    const string& color,
    const string& backgroundColor,
    const string& style
) {
  // Define prefix and suffix.
  string prefix = "\033[";
  string suffix = "\033[0m";

  // Define the color codes.
  map<string, string> colors = {
      {"black", "30"},
      {"red", "31"},
      {"green", "32"},
      {"yellow", "33"},
      {"blue", "34"},
      {"magenta", "35"},
      {"cyan", "36"},
      {"white", "37"}
  };

  // Define the background color codes.
  map<string, string> backgroundColors = {
      {"black", "40"},
      {"red", "41"},
      {"green", "42"},
      {"yellow", "43"},
      {"blue", "44"},
      {"magenta", "45"},
      {"cyan", "46"},
      {"white", "47"}
  };

  // Define the style codes.
  map<string, string> styles = {
      {"bold", "1"},
      {"underline", "4"},
      {"blink", "5"},
      {"invert", "7"}
  };

  // Define the codes vector.
  vector<string> codes;

  // Check if the color is valid.
  if (colors.find(color) != colors.end()) {
    codes.push_back(colors[color]);
  }

  // Check if the background color is valid.
  if (backgroundColors.find(backgroundColor) != backgroundColors.end()) {
    codes.push_back(backgroundColors[backgroundColor]);
  }

  // Check if the style is valid.
  if (styles.find(style) != styles.end()) {
    codes.push_back(styles[style]);
  }

  // Check if there are no codes.
  if (codes.empty()) {
    return str;
  }

  // Join the codes, prefix and suffix.
  string output = prefix;
  for (unsigned int i = 0; i < codes.size(); i++) {
    output += codes[i];
    if (i != codes.size() - 1) {
      output += ";";
    }
  }
  output += "m" + str + suffix;

  // Return the output.
  return output;
}

// Function that clears the console.
void clearConsole() {
#if _WIN32
  system("cls");
#else
  cout << "\033[2J\033[1;1H";
#endif
}

// Function that converts milliseconds to time string.
string millisecondsToTimeString(unsigned long long milliseconds) {
  // Define the time string.
  string timeString;

  // Calculate the hours.
  unsigned int hours = int(milliseconds / 3600000);

  // Calculate the minutes.
  unsigned int minutes = int((milliseconds % 3600000) / 60000);

  // Calculate the seconds.
  unsigned int seconds = int(((milliseconds % 3600000) % 60000) / 1000);

  // Calculate the milliseconds.
  unsigned int ms = int(((milliseconds % 3600000) % 60000) % 1000);

  // Check if the hours, minutes and seconds are 0.
  if (hours == 0 && minutes == 0 && seconds == 0) {
    return to_string(ms) + "ms";
  }

  // Check if the hours are greater than 0.
  if (hours > 0) {
    timeString += to_string(hours) + "h ";
  }

  // Check if the minutes are greater than 0.
  if (minutes > 0) {
    timeString += to_string(minutes) + "m ";
  }

  // Check if the seconds are greater than 0.
  if (seconds > 0) {
    // Get first two digits of the milliseconds.
    string msStr = to_string(ms);
    if (msStr.size() == 1) {
      msStr = "0" + msStr;
    } else if (msStr.size() > 2) {
      msStr = msStr.substr(0, 2);
    }

    // Add the seconds and milliseconds to the time string.
    timeString += to_string(seconds) + "." + msStr + "s ";
  }

  // Trim last space.
  if (timeString[timeString.size() - 1] == ' ') {
    timeString = timeString.substr(0, timeString.size() - 1);
  }

  // Return the time string.
  return timeString;
}

// Function that generates a progress bar string.
string generateProgressBarString(unsigned int percentage, unsigned int maxNumberOfBlocks) {
  // Define the progress bar string.
  string progressBarString;

  // Check if the percentage is greater than 100.
  if (percentage > 100) {
    percentage = 100;
  }

  // Calculate the number of blocks.
  unsigned int numberOfBlocks = int(maxNumberOfBlocks * (percentage / 100.0));

  // Calculate the number of empty blocks.
  unsigned int numberOfEmptyBlocks = maxNumberOfBlocks - numberOfBlocks;

  // Add the blocks to the progress bar string.
  for (unsigned int i = 0; i < numberOfBlocks; i++) {
    progressBarString += PROGRESS_BAR_FULL_SYMBOL;
  }

  // Add the empty blocks to the progress bar string.
  for (unsigned int i = 0; i < numberOfEmptyBlocks; i++) {
    progressBarString += PROGRESS_BAR_EMPTY_SYMBOL;
  }

  // Return the progress bar string.
  return progressBarString;
}
