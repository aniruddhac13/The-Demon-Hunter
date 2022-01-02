#include <bits/stdc++.h>
#include "leaderboard.h"

using namespace std;

// Persistent (binary file used: scores.dat) leader board
LeaderBoard::LeaderBoard()
{
    clear();
    // Open scores.dat saved in previous session, if any
    ifstream scoreFile("scores.dat", ios::in | ios::binary);
    int playerId = 0;
    int score = 0;
    // If the scores.dat existed, load the scores from previous session
    if(scoreFile.is_open())
    {
        while(!scoreFile.eof())
        {
            // Read the player id
            scoreFile.read((char *)(&playerId), sizeof(playerId));
            // Read player's score
            scoreFile.read((char *)(&score), sizeof(score));
            // Add the score record to the players map
            players[playerId] = score;
            // Add the score record to scores max queue
            scores.push({players[playerId], playerId});
        }
        // Close the scores.dat
        scoreFile.close();
    }
}

LeaderBoard::~LeaderBoard()
{
    // Clear all the fields
    clear();
}

// Store/update <playerId, score>
void LeaderBoard::updateScore(int playerId, int score)
{
    // Store/update <playerId, score> in players map
    if(players.find(playerId) != players.end())
        // For existing player update the score with input increment or decrement
        players[playerId] += score;
    else
        // For new player create entry for <playerId, score>
        players[playerId] = score;
    // Scores stored in priority queue for getting top scorers
    // First field is score and seconf is player so that max queue uses score
    scores.push({players[playerId], playerId});
}

vector<pair<int, int>> LeaderBoard::getTopN(int topn)
{
    // Result vector for topn scorers
    vector<pair<int, int>> topPlayerScores;
    // Take care of duplicate (old) entries of topn scorers in scores priority queue
    map<int, bool> alreadyInTop;
    int numPlayers = (int)players.size();
    if(topn > numPlayers)
        topn = numPlayers;
    while(topn)
    {
        pair<int, int> cur = scores.top();
        scores.pop();
        // Validate if the player exists in the players map
        if((players[cur.second] == cur.first) && (alreadyInTop.find(cur.second) == alreadyInTop.end()))
        {
            alreadyInTop[cur.second] = true;
            // Update result vector with first/next top scorer
            topPlayerScores.push_back(cur);
            topn--;
        }
    }
    // Restore back the top scores popped in logic above
    for(int i = 0; i < (int)topPlayerScores.size(); i++)
        scores.push(topPlayerScores[i]);
    // Return the result vector
    return topPlayerScores;
}

// Reset score of given player to 0
void LeaderBoard::reset(int playerId)
{
    players[playerId] = 0;
}

// Save the leader board to scores.dat
void LeaderBoard::save()
{
    ofstream scoreFile("scores.dat", ios::out | ios::binary);
    pair<int, int> playerScore;
    // If scores.dat can be opened without errors, persist the leader board in it
    if(scoreFile.is_open())
    {
        // Iterate through players and write the player ID followed by the score in scores.dat file
        for(auto playerScore : players)
        {
            scoreFile.write((const char *)(&playerScore.first), sizeof(playerScore.first));
            scoreFile.write((const char *)(&playerScore.second), sizeof(playerScore.second));
        }
        // Close the scores.dat
        scoreFile.close();
    }
}

// Clear the leader board (clear all the fields)
void LeaderBoard::clear()
{
    players.clear();
    while(!scores.empty())
        scores.pop();
}

