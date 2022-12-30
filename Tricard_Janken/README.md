
# TriCard Janken (Rock, Paper, & Scissor) C++ 

## Terminal/CommandPrompt Card Game inspired from Kakegurui S1Ep1, which every round all students other than player creates a card of Rock, Paper and Scissor, then cards will put into hollow box. The players will draw 3 card. This game is RNG based system, my brain can't squeeze enough to make better A.I. without breaking the program heh.

## - Game Guidelines - 
1. There will be money at stake when the round starts. As the round starts there will be money at stake. 
2. There'll be 10 cards on the deck, and a brand new set of card on the deck to the following round
3. Then, it will be distributed 1 each after another, until there's only 3 cards on hand
4. Players will choose 1 from the 3 cards at hand to play, then the to game is concluded. 
5. If the result is a DRAW, players will play from the remaining cards on hand. 
6. When the game concludes all bets will be given to the winner. 
7. In this case MONEY is your LIFE.

## - Restriction for BET -
* An error occur during the value of bet is 1, so I decided to invalidate:
1. The value of 1 as bet
2. When the difference of money and input bet is equal to 1
- Special Condition -
1. When there's remaining value of 2 as money it's automatically turn as bet
2. When you incorrectly bet 3 times, your whole money will turn as bet

---

Note : This program is meant to be Functional, basically to separate functions as its structure. But I decided to remake it, because from the uncaught errors and its spaghetti code,  and now I chose Object-Oriented Programming (OOP) Paradigm, and it's like how "struct" works.

PS: Open for correction, suggestion and such. If you however tried to make your own version, If you may, kindly post it here also.
baka trip nyo itry, Thank you!! Enjoy! Heh. 