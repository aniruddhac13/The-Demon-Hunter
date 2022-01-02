#ifndef __LEADERBOARD_H
#define __LEADERBOARD_H

#include <bits/stdc++.h>

using namespace std;

// Persistent (binary file used: scores.dat) leader board
class LeaderBoard
{
    // Scores stored in priority queue for getting top scorers
    // First field is score and second is player so that max queue uses score
    priority_queue<pair<int, int>> scores;
    // Map to store/update <playerId, score> via updateScore function
    map<int, int> players;

public:
    // Load the persistent leader board
    LeaderBoard();
    // Clear players and scores
    ~LeaderBoard();
    // Store and/or update score of given player (cumulative)
    // score input can be positive or negative
    void updateScore(int playerId, int score);
    // Get top N scorers for score board display
    vector<pair<int, int>> getTopN(int topn);
    // Reset score of given player to 0
    void reset(int playerId);
    // Save the leader board to scores.dat
    void save();
    // Clear playres and scores
    void clear();
};

#endif //__LEADERBOARD_H

