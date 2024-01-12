# RouletteSimulation

A popular strategy in the casino game roulette is to double your bet for every loss. This goes for most games with a near 50% win rate with 2 to 1 odds.
The reason for this is that if you keep doubling the bet after every loss, you are guaranteed to make a profit of your initial bet amount.
The odds of doubling and losing again and again grow exponentially similar to flipping a coin: the odds of flipping a coin 7 times and getting heads at least once is 99.2%.
However, a 5-dollar initial bet would also now be $640.

This roulette simulation adds two protections.
1. Setting a max bet value. This ensures that after doubling several times, you are not making a ridiculously high bet.
2. Setting a balance goal. This is a cash-out goal that will ensure you walk out after reaching your bet rather than continue playing.

This simulation will test all possible max bet values based on a maximum value set in a macro along with all balance goals.
After the simulation is complete, the most optimal max bet and balance goals will be output to the console.
