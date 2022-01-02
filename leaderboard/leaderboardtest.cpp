#include <bits/stdc++.h>
#include "leaderboard.h"

int main()
{
    // Create instance of leader board
    LeaderBoard leaderboard;
    // Add/update players and scores in the leader board
    leaderboard.updateScore(1,73);
    leaderboard.updateScore(2,56);
    leaderboard.updateScore(3,-39);
    leaderboard.updateScore(4,51);
    leaderboard.updateScore(5,12);
    leaderboard.updateScore(6,-74);
    // Query top 3 scorers
    vector<pair<int, int>> topScores = leaderboard.getTopN(10);
    // Output top N players and scorers
    // If N > totalplayers, N = totalplayers
    for(auto topScore : topScores)    
        cout << "Player :" << topScore.second << " scored " << topScore.first << endl;
    // Do some updates to scores of few players
    leaderboard.reset(1);
    leaderboard.reset(2);
    leaderboard.updateScore(2,50);
    // Query top 3 scorers again
    topScores = leaderboard.getTopN(3);
    // Output top N players and scorers
    // If N > totalplayers, N = totalplayers
    for(auto topScore : topScores)    
        cout << "Player :" << topScore.second << " scored " << topScore.first << endl;
    // Save the leader board
    leaderboard.save();
    return 0;
}

