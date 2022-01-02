=========================================================================================================================

Persistent (binary file used: scores.dat) leader board
======================================================

1. Map to store/update <playerId, score> via updateScore function
2. Scores stored in priority queue (of <score, player> pairs) for getting top scorers.
   First field is score and second is player so that max queue uses score.

=========================================================================================================================

Interfaces and usage
====================

[Please refer to the leaderboard.h for interface (method) prototypes.]
[Please refer to the leaderboardtest.cpp for interface usage.]

1. Create leader board instance as:
   LeaderBoard leaderboard;
   This will load the persistent leader board from scores.dat file if one exists.

2. To update score of existing player or add score of new player call updateScore interface.
   It stores and/or updates score of given player (cumulative).
   The score input can be positive or negative depending on the score update required for the player.

3. To get top N scorers in the game, call getTopN interface.
   It returns vector<pair<int, int>> containing pairs of <score, player> of top N players (if N > totalplayers then N =totalplayers).

4. To reset score of given player to 0 call reset interface with player ID as parameter.

5. Whenever required (ex. before exiting game) save the leader board to scores.dat by calling save interface.

6. To clear the leader board i.e. to remove all players and scores from it, call clear interface.

=========================================================================================================================

Demo, build and run
===================

# Remove existing scores.dat for fresh run
$ rm -f scores.dat 

# Compile / build
$ g++ -Wall -o leaderboard leaderboard.cpp leaderboardtest.cpp

# First Run
$ ./leaderboard
Player :1 scored 73
Player :2 scored 56
Player :4 scored 51
Player :5 scored 12
Player :3 scored -39
Player :6 scored -74
Player :4 scored 51
Player :2 scored 50
Player :5 scored 12

# Scores are persisted in scores.dat (gets created after first run)
$ ls scores.dat 
scores.dat

# Second Run (demonstrates cumulative scores, uses scores from previous session stored in scores.dat)
$ ./leaderboard
Player :2 scored 106
Player :4 scored 102
Player :1 scored 73
Player :5 scored 24
Player :3 scored -78
Player :6 scored -148
Player :4 scored 102
Player :2 scored 50
Player :5 scored 24

=========================================================================================================================

