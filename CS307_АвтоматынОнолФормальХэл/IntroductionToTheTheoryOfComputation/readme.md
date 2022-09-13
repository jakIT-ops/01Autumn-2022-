# Introduction


## 0.1 AUTOMATA, COMPUTABILITY, AND COMPLEXITY


### COMPLEXITY THEORY

Computer problems come in different varieties; some are easy, and some are hard. For example: the sorting problem is an easy one. 

### COMPUTABILITY THEORY

During the first half of the twentieth century, mathematicians such as Kurt Godel, Alan Turing, and Alonzo Church discovered that certain basic problems ¨ cannot be solved by computers. One example of this phenomenon is the problem of determining whether a mathematical statement is true or false. This task is the bread and butter of mathematicians. It seems like a natural for solution by computer because it lies strictly within the realm of mathematics. But no computer algorithm can perform this task.

### AUTOMATA THEORY

Automata theory deals with the definitions and properties of mathematical models of computation. One model, called the `finite automaton`, is used in text proecessing, compilers, and hardware design. Another model, called the `context-free grammer` is used in programming languages and artificial intelligence. Automata theory is an excellent place to begin the study of the theory of computation. The theories of computability and complexity require a precise definition of a computer. Automata theory allows practice with `formal` definitions of computation as it introduces concepts relevant to other `nontheoretical` areas of computer science.


## 0.2 MATHEMATICAL NOTIONS AND TERMINOLOGY

### SETS

A `set` is a group of obects represented as a unit. Sets may contain any type of object, including numbers, symbols, and even other sets. The objects in a set are called its elements or members. Sets may be described formally in several ways. 

```
S = {7, 21, 57}
```

### SEQUENCES AND TUPLES 

A `sequence` of objects is a list of these objects in some order. 

```
(7, 21, 57)
```

EXAMPLES 

```
if A = {1, 2} and B = {x, y, z},
	A x B = {(1,x), (1,y), (1,z), (2,x), (2,y), (2,z)}.
```

```
If A and B are as in

	A × B × A = (1, x, 1), (1, x, 2), (1, y, 1), (1, y, 2), (1, z, 1), (1, z, 2),
		    (2, x, 1), (2, x, 2), (2, y, 1), (2, y, 2), (2, z, 1), (2, z, 2) 	

```

```
The set N^2 equals N x N. it consists of all ordered pairs of natural numbers. We also may write it as {(i,j|i,j >= 1)}.
```

### FUNCTIONS AND RELATIONS

Functions are central to mathematics A `function` is an object that sets up an input-output relationship. 

### GRAPHS

An `undirected graph`, or simply a `graph`, is a set of points  with lines connectiong some of the points. The points are called `nodess` or `vertices`, and the lines are called `edges`

### STRINGS AND LANGUAGES

Strings of characters are funamental building blocks in computer science.

### BOOLEAN LOGIC

`Boolean logic` is a mathematical system built around the two values TRUE and FALSE, Though originally conceived of as pure mathematics

```
P ∨ Q ¬(¬P ∧ ¬Q)
P → Q ¬P ∨ Q
P ↔ Q (P → Q) ∧ (Q → P)
P ⊕ Q ¬(P ↔ Q)
```

### SUMMARY OF MATHEMATICAL TERMS

```
Alphabet 		A finite, nonempty set of objects called symbols
Argument 		An input to a function
Binary relation 	A relation whose domain is a set of pairs
Boolean operation 	An operation on Boolean values
Boolean value 		The values TRUE or FALSE, often represented by 1 or 0
Cartesian product 	An operation on sets forming a set of all tuples of elements from respective sets
Complement 		An operation on a set, forming the set of all elements not present
Concatenation 		An operation that joins strings together
Conjunction 		Boolean AND operation
Connected graph 	A graph with paths connecting every two nodes
Cycle 			A path that starts and ends in the same node
Directed graph 		A collection of points and arrows connecting some pairs of points
Disjunction 		Boolean OR operation
Domain 			The set of possible inputs to a function
Edge 			A line in a graph
Element 		An object in a set
Empty set 		The set with no members
Empty string 		The string of length zero
Equivalence relation 	A binary relation that is reflexive, symmetric, and transitive
Function 		An operation that translates inputs into outputs
Graph 			A collection of points and lines connecting some pairs of points
Intersection 		An operation on sets forming the set of common elements
k-tuple 		A list of k objects
Language 		A set of strings
Member 			An object in a set
Node 			A point in a graph
Ordered pair 		A list of two elements
Path 			A sequence of nodes in a graph connected by edges
Predicate 		A function whose range is {TRUE, FALSE}
Property 		A predicate
Range 			The set from which outputs of a function are drawn
Relation		A predicate, most typically when the domain is a set of k-tuples
Sequence 		A list of objects
Set 			A group of objects
Simple path 		A path without repetition
Singleton set 		A set with one member
String 			A finite list of symbols from an alphabet
Symbol 			A member of an alphabet
Tree 			A connected graph without simple cycles
Union 			An operation on sets combining all elements into a single set
Unordered pair 		A set with two members
Vertex 			A point in a graph
```

## 0.3 DEFINITIONS, THEOREMS, AND PROOFS

Theorems and proofs are the heart and soul of mathematics and definitions are its spirit. These three entities are central to every mathematical subject, including ours.

`Definitions` describe the objects and notions that we use. 

A` proof` is a convincing logical argument that a statement is true. 

A `theorem` is mathematical statement proved true.

### FINDING PROOFS

Математикийн нотолгоонд(proof) хэд хэдэн төрлийн аргументууд байнга гарч ирдэг. Энд бид тооцооллын онолд ихэвчлэн тохиолддог цөөн хэдэн зүйлийг тайлбарлав. Нотолгоо нь хэд хэдэн өөр дэд нотлох баримтуудыг агуулж болох тул нэгээс олон төрлийн аргумент агуулж болохыг анхаарна уу

`PROOF` Let n be an even number greater that 2. Constuct graph G = (V, E) with n nodes as follows. The set of nodes of G is V = {0, 1, .........., n - 1}, and the set of edges of G is the set

```
E = {{i, i + 1} | for 0 <= i <= n - 2} U {{n - 1, 0}} U {{i, i + n / 2} | for 0 <= i <= n / 2 - 1}.
```





























































































































































