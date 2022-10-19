## TODO List and planned tests:
#### 1. Discovering floor - is this needed?
- **Description:** Remove giving reward for discovering floor fragments (+1), and remove "discovered floor" from state
matrix. State matrix will reduce to 20x20x4 because of this.
- **Status:** In progress  
- **Result:** TBD

#### 2. Add static enemies to level.
- **Description:** Add static enemies to level and learn AI to win level with enemies. State matrix will be 
expanded to 20x20x5.
- **Status:** Waiting to be done
- **Result:** TBD

#### 3. Neural network size tests.
- **Description:** If the results after adding enemies will be encouraging, several cases will be tested. Depending 
on the results, the tests will be repeated or not.
- **Status:** Waiting to be done
- **Result:** TBD

*Case 1:*
- Layers: 1
- Neurons: [600], [1000], [1400], [1800], [2200], [2600]

*Case 2:*
- Layers: 2
- Neurons: [800, 600], [1000, 1000], [1400, 1000], [1600, 1200], [1800, 1400], [2000, 1600]

#### 4. Adding moving enemies to level:
- **Description:** Add moving enemies to level and learn AI to win level with moving enemies as well. State matrix
will not be expanded, as moving enemy will have same state as static enemy.
- **Status:** Waiting to be done
- **Result:** TBD

#### 5. Attempt to eliminate overfitting:
- **Description:** Actually, AI learns how to win level, but target NN is strong overfitted with level in which AI
were learning. There are idea to solve it - levels will be drawn from a pool of 20-30.
- **Status:** Waiting to be done
- **Result:** TBD

#### 6. Rest of hiperparameters tuning:
- **Description:** These parameters should be tested with different values: batch_size, huber_delta, epsilon, 
replace_target and maybe mem_size.
- **Status:** Waiting to be done
- **Result:** TBD

#### 7. Test CNN instead of NN
- **Description:** Check how Convolutional Neural Network will handle learning in DDQN algorithm.
- **Status:** Waiting to be done
- **Result:** TBD
