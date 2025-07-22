# 🧬 Genetic Algorithm – Solving the Travelling Salesman Problem (TSP)


Language: C++ | Paradigm: Object-Oriented Programming (OOP)

This project demonstrates an object-oriented implementation of a Genetic Algorithm (GA) to solve the classic Travelling Salesman Problem (TSP) — an NP-hard optimization problem that involves finding the shortest possible route visiting a set of cities exactly once and returning to the origin.

🔍 Core Concept:

Inspired by the principles of natural selection and evolutionary biology, the genetic algorithm simulates processes such as selection, crossover, and mutation to iteratively evolve a population of candidate solutions toward an optimal or near-optimal tour.


🛠️ Key Components & Features:

Population Initialization:
A randomly generated population of valid city routes (chromosomes) is created at the start, representing different potential solutions.

Fitness Evaluation:
Each individual (route) is evaluated based on the total travel distance. Shorter routes receive higher fitness scores.

Selection Mechanism:
Utilizes methods like tournament selection or roulette wheel selection to probabilistically choose fitter individuals for reproduction.

Crossover Operation:
Implements crossover techniques (e.g., Order Crossover (OX) or Partially Mapped Crossover) to combine two parent routes and produce offspring that retain characteristics from both while maintaining valid permutations of cities.

Mutation Strategy:
Applies small random changes (e.g., swap mutation or inversion mutation) to introduce variability and prevent premature convergence.

Termination Criteria:
The algorithm runs until a stopping condition is met—either a maximum number of generations or convergence to an optimal (or satisfactory) solution.


⚙️ Object-Oriented Design:

Encapsulated key logic in reusable classes such as:
City
Route
Population
GeneticAlgorithm
Promotes modularity, ease of testing, and future enhancements.


📈 Outcome:

The final result is a near-optimal travel route computed from an initially random pool of candidates. This project not only demonstrates algorithmic problem-solving but also strong proficiency in C++, OOP principles, and optimization heuristics.


🌱 Potential Enhancements:

Visualization of route progression over generations
Multi-threaded fitness evaluations for performance boost
Parameter tuning (mutation rate, population size) for better convergence
