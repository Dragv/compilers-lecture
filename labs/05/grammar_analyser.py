import sys
import ast

with open(sys.argv[1], 'r') as f:
    s = f.read()
    CFG = ast.literal_eval(s)

reducedCFG = {}
noGoodNonterminals = []
previous = ''
startingPoint = 'S'
stack = []
stack.append(startingPoint)
while not len(stack) == 0:
    production = stack.pop()
    reducedCFG[production] = CFG[production]
    for element in CFG[production]:
        if element.isupper():
            if(element == previous):
                noGoodNonterminals.append(element)
                break
            stack.append(element)
            previous = production

keysCFG = set(CFG.keys())
keysReducedCFG = set(reducedCFG.keys())
difference = keysCFG - keysReducedCFG
print("List of nonterminals that cause trouble:", noGoodNonterminals + list(difference))