class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int main_count = 0;
        for (auto sentence : sentences) {
            int count_word = 1;
            for (int i = 0; i < sentence.size(); i++) {
                if (sentence[i] == ' ') {
                    count_word++;
                }
            }
            main_count = max (main_count, count_word);
        }
        return main_count;
    }
};