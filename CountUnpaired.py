#This matched pairs problem can be easily solved with sorting, however sorting unknown integers has a runtime of O(nLog(n)). We can do better.
#I think sets are a better solution, just add the number when you see it once, remove it the next time you see it, then repeat.
#At the end, your set contains each unmatched pair. This should be O(n).

def countUnpaired(input):
  mySet = set();
  for i in range(0,len(input)):
    if input[i] in mySet:
      mySet.remove(input[i]);
    else:
      mySet.add(input[i]);
  return len(mySet)

#if this is attached with an include, don't run test cases.
if __name__ == "__main__":
  testCases =[
    [1,2,3,4],
    [1,1,2,2,3,3,4,4],
    [1,2,2,3,3,3,4,4,4,4],
    [4,3,2,1,3,2,1,2,1,1],
    []
  ];
  for i in range(0,len(testCases)):
    print(countUnpaired(testCases[i]));