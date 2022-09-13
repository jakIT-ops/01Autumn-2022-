# 1. Удирдтгал 

## Тооцооллын онол (Theory of Comutation) 

### Автомат / AUTOMATA 

* Тооцооллын математик загварууд 4 төрлийн автомат байдаг: Finite State Automata, Push Down, Automata,Linear Bounded Automata, Turing Machine 

* Тооцооллын формйл тодорхойлолтыг практикт хэрэгжүүлэхэд чиглэсэн. 

### Тооцогдохуй / COMPUTABILITY

* Тухайн объектыг шийдэх боломжтой эсэх

* Yes/No - Decision problem Turing Machine• Компьютерээр шийдвэрлэх

* Halting Problem 

### Хүндрэл / COMPLEXITY

* Чухам юу асуудлыг тооцооллын хувьд хялбар эсвэл хэцүү болгоод байгааг тодорхойлох

* Тухайн асуудлыг тооцооллын бэрхшээлийнх нь хувьд ангилах

## Формаль хэл, Автоматын онол

* Type-0 -> Unristricted Grammer (Recognized by Turing Machine) // example: personal computer

* Type-1 -> Context Sesitive Grammer (Acccepted by Linear Bound Automata) // example: printing 

* Type-2 -> Context Free Grammer (Accepted by Push Down Automata) // example: NLP

* Type-3 -> Regular Grammer(Accepted By Finite Automata) // example: ATM

### Тооцооллын хүндрэл (Computational complexity, 1960s)

> `Алгоритм` гэдэг нь тооцоолол гүйцэтгэх заавруудынтөгсгөлөг 𝑛 дараалал юм. `Хугацааны хүндрэл (Time Complexity)` : TIME(f(n)) `Зайн хүндрэл (Space Complexity)` : SPACE(g(n))

`Deterministic O(n^k)`

> P = Uk TIME(n^k)

`nonDeterministic` O(n^k)

> NP = Uk NTIME(n^k)

