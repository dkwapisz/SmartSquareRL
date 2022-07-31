1. state = get_state(game)
2. action = get_action(state) -> random or RL
3. reward, game_over = game.step(action)
4. new_state = get_state(game)
5. remember(state, action, reward, new_state, game_over)
6. learn()

Exchange - every call get single state and return single action to perform

### Correct order:

1. Exchange
   1. Get state from game
   2. Calculate and send action
2. Play game step and get reward/game_over
3. Get new state from game
4. Remember(state, action, reward, new_state, game_over)
5. Learn()

