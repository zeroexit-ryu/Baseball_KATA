#include <stdexcept>

using namespace std;

struct GuessResult {
	bool solved;
	int strikes;
	int balls;
};

class Baseball {
public:
	explicit Baseball(const string& question) : question(question) {

	}

	GuessResult guess(const string& guessNumber) {
		asserttIllegalArgument(guessNumber);

		GuessResult result{ false, 0, 0 };
		for (int pos = 0; pos < 3; pos++)
		{
			if (guessNumber[pos] == question[pos]) {
				result.strikes++;
			}
			else {
				for (int ball_check_pos = 0; ball_check_pos < 3; ball_check_pos++) {
					if (guessNumber[pos] == question[ball_check_pos]) result.balls++;
				}
			}
		}

		if (result.strikes == 3) result.solved = true;

		return result;
	}

	void asserttIllegalArgument(const std::string& guessNumber)
	{
		if (guessNumber.length() != 3) {
			throw length_error("Must be three letters.");
		}

		for (char ch : guessNumber) {
			if (ch >= '0' && ch <= '9') continue;
			throw invalid_argument("Must be number");
		}

		if (isDuplicatedNumber(guessNumber)) {
			throw invalid_argument("Must not have the same number");
		}
	}

	bool isDuplicatedNumber(const std::string& guessNumber)
	{
		return guessNumber[0] == guessNumber[1]
			|| guessNumber[0] == guessNumber[2]
			|| guessNumber[1] == guessNumber[2];
	}

private:
	string question;
};