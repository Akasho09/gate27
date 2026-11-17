# Serializability
Serializability is a correctness criterion used to determine whether a non-serial schedule is equivalent to some serial schedule.

## Types of Serializability
1. Conflict Serializability
Based on conflicting operations

2. View Serializability
Based on read-from and final-write relationships

## Conflict Equivalent Schedules


## Conflict Serializability | Precedence Graph
- A schedule is conflict serializable if it can be transformed into a serial schedule by swapping non-conflicting operations.

### Precedence Graph?
A Precedence Graph is a directed graph used to determine whether a schedule is conflict serializable.

It consists of:
- Vertices (Nodes): Transactions.
- Directed Edges: Conflict-based dependencies between transactions.

