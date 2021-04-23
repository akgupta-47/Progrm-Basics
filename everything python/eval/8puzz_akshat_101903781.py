import copy


class Puzzle:
    def __init__(self, initialPositions, goalState):
        super().__init__()
        self.positions = initialPositions
        self.zero = initialPositions.index(0)
        self.goalState = goalState
        self.col = 3

    def down(self):
        if self.zero < 6:
            self.positions[self.zero] = self.positions[self.zero+3]
            self.positions[self.zero+3] = 0
            self.zero = self.zero+3
            return True
        else:
            return False

    def up(self):
        if self.zero - self.col >= 0:
            self.positions[self.zero] = self.positions[self.zero-3]
            self.positions[self.zero-3] = 0
            self.zero = self.zero-3
            return True
        else:
            return False

    def left(self):
        if self.zero % self.col > 0:
            self.positions[self.zero] = self.positions[self.zero-1]
            self.positions[self.zero-1] = 0
            self.zero = self.zero-1
            return True
        else:
            return False

    def right(self):
        if self.zero % self.col < self.col-1:
            self.positions[self.zero] = self.positions[self.zero+1]
            self.positions[self.zero+1] = 0
            self.zero = self.zero+1
            return True
        else:
            return False

    def isGoalState(self):
        if self.goalState == self.positions:
            print("Goal State is reached")
            print("---------------------------")
            return True
        return False

    def displayState(self):
        for i in range(0, 3):
            print(self.positions[i*3 + 0],
                  self.positions[i*3+1], self.positions[i*3+2])
        print("---------------------------")


closed_list = []
open_stack = []


def checkClosedList(positions):
    if positions in closed_list:
        return False
    return True


def depthLimitedSearch(state, limit):
    print("Initial State => ")
    state.displayState()

    open_stack.append(state)

    while len(open_stack) != 0:
        if limit <= 0:
            print('sorry limit reached')
            return
        else:
            node = open_stack.pop(0)  # pop(0) and insert(0) results in DFS
            closed_list.append(node.positions)

            if node.isGoalState():
                node.displayState()
                print("Closed List Length => ", len(closed_list))
                print("Open List Length => ", len(open_stack))
                break

            new_state_right = copy.deepcopy(node)
            if new_state_right.right() and checkClosedList(new_state_right.positions):
                open_stack.insert(0, new_state_right)
            else:
                del new_state_right

            new_state_down = copy.deepcopy(node)
            if new_state_down.down() and checkClosedList(new_state_down.positions):
                open_stack.insert(0, new_state_down)
            else:
                del new_state_down

            new_state_left = copy.deepcopy(node)
            if new_state_left.left() and checkClosedList(new_state_left.positions):
                open_stack.insert(0, new_state_left)
            else:
                del new_state_left

            new_state_up = copy.deepcopy(node)
            if new_state_up.up() and checkClosedList(new_state_up.positions):
                open_stack.insert(0, new_state_up)
            else:
                del new_state_up

            limit -= 1


puzzle = Puzzle([2, 0, 3, 1, 8, 4, 7, 6, 5], [1, 2, 3, 8, 0, 4, 7, 6, 5])
depthLimitedSearch(puzzle, 40)
