isMale(john).
isMale(briten).
isMale(daron).
isFemale(mary).
isFemale(maria).
isParent(briten,john).
isParent(maria,john).
isBroOrSis(mary,maria).
isBroOrSis(daron,briten).
isAunt(C,B) :- isParent(A,B),isFemale(C),isBroOrSis(C,A).
isUncle(C,B) :- isParent(A,B),isMale(C),isBroOrSis(C,A).
