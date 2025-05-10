# ✈️ Travelling Salesman Problem (TSP)

---

## 📌 What is the Travelling Salesman Problem?

The **Travelling Salesman Problem (TSP)** asks:

> Given a list of cities and the distances between each pair, what is the **shortest possible route** that visits each city **exactly once** and returns to the starting point?

It’s one of the most famous problems in computer science and **combinatorial optimization**.

---

## 🧭 Why Do We Need It?

TSP is used in:
- **Logistics & Delivery**: Planning optimal delivery routes (e.g., Amazon, FedEx)
- **Manufacturing**: Tool path optimization for drilling, cutting, or painting
- **Circuit Design**: Minimizing the length of wire paths
- **Robotics**: Efficient path planning
- **Genomics**: DNA sequencing and genome assembly

---

## 🧠 Approaches Explained

### 1. **Brute Force**
- Try all possible routes (permutations of cities)
- Select the shortest one
- **Time Complexity**: O(n!)  
  *(Terribly slow for large `n`!)*

### 2. **Dynamic Programming (Held-Karp)**
- Use **memoization + bitmasking** to avoid recalculating
- Much faster than brute-force for moderate `n`
- **Time Complexity**: O(n² · 2ⁿ)

---

## 🗺️ Example

Imagine 4 cities: A, B, C, D  
And the distances:
# ✈️ Travelling Salesman Problem (TSP) – A Friendly Guide

---

## 📌 What is the Travelling Salesman Problem?

The **Travelling Salesman Problem (TSP)** asks:

> Given a list of cities and the distances between each pair, what is the **shortest possible route** that visits each city **exactly once** and returns to the starting point?

It’s one of the most famous problems in computer science and **combinatorial optimization**.

---

## 🧭 Why Do We Need It?

TSP is used in:
- **Logistics & Delivery**: Planning optimal delivery routes (e.g., Amazon, FedEx)
- **Manufacturing**: Tool path optimization for drilling, cutting, or painting
- **Circuit Design**: Minimizing the length of wire paths
- **Robotics**: Efficient path planning
- **Genomics**: DNA sequencing and genome assembly

---

## 🧠 Approaches Explained

### 1. **Brute Force**
- Try all possible routes (permutations of cities)
- Select the shortest one
- **Time Complexity**: O(n!)  
  *(Terribly slow for large `n`!)*

### 2. **Dynamic Programming (Held-Karp)**
- Use **memoization + bitmasking** to avoid recalculating
- Much faster than brute-force for moderate `n`
- **Time Complexity**: O(n² · 2ⁿ)

---

## 🗺️ Example

Imagine 4 cities: A, B, C, D  
And the distances:
  - A-B: 10, A-C: 15, A-D: 20  
  - B-C: 35, B-D: 25  
  - C-D: 30

Your task:  
Find the shortest round-trip that starts and ends at A and visits each city once.

---

## ⚙️ How Do Brute Force & DP Differ?

| Feature              | Brute Force     | Dynamic Programming |
|----------------------|-----------------|---------------------|
| Speed                | ❌ Very slow    | ✅ Much faster     |
| Logic                | All permutations| Smart memoization   |
| Space Used           | Low             | Higher              |
| Max Cities (practical) | ~8–10         | ~18–22              |

---

## ⏱️ Time & Space Complexity

| Operation            | Brute Force     | Held-Karp (DP)      |
|----------------------|-----------------|---------------------|
| Time Complexity      | O(n!)           | O(n² · 2ⁿ)          |
| Space Complexity     | O(1)            | O(n · 2ⁿ)           |

---

## 🖼️ Real-World Analogy

Imagine a **salesperson** trying to visit multiple cities and return home with the **least travel cost**.

Brute-force is like:
> “Let me try **every** possible route and pick the best.”

Dynamic Programming is like:
> “Let me **remember** what I've already calculated and reuse it wisely.”

---

## 🎥 Bonus: Video Explanation

Watch my YouTube video explaining the TSP problem, brute-force and dynamic programming approach with examples.

[![TSP YouTube](https://img.youtube.com/vi/YOUR_VIDEO_ID/0.jpg)](https://www.youtube.com/watch?v=YOUR_VIDEO_ID)

---

## ❓ Quiz Time: Test Your Understanding

### **1. What does the Travelling Salesman Problem try to minimize?**

A. Number of cities visited  
B. Cost of the trip  
C. Number of delivery vehicles  
D. Number of paths from each city  

✅ **Correct Answer:** B

---

### **2. What is the time complexity of the brute-force TSP approach?**

A. O(n²)  
B. O(log n)  
C. O(n!)  
D. O(n² · 2ⁿ)  

✅ **Correct Answer:** C

---

### **3. What is the time complexity of the Held-Karp (DP) TSP approach?**

A. O(n²)  
B. O(log n)  
C. O(n!)  
D. O(n² · 2ⁿ)  

✅ **Correct Answer:** D

---

### **4. In practice, what’s the max number of cities brute-force TSP can handle efficiently?**

A. 3–4  
B. 8–10  
C. 20–25  
D. 50+  

✅ **Correct Answer:** B

---

### **5. What’s the best real-world example of where TSP is useful?**

A. Sorting numbers  
B. Encrypting passwords  
C. Planning delivery routes  
D. Making chat apps  

✅ **Correct Answer:** C

---

## ✨ Summary

| Topic       | Key Point                                 |
|-------------|--------------------------------------------|
| TSP         | Find shortest tour through all cities     |
| Brute Force | Tries all permutations, slow               |
| DP (Held-Karp)| Reuses past results, much faster         |
| Use Cases   | Delivery, routing, circuit design, robotics|
| Complexity  | Brute: O(n!), DP: O(n² · 2ⁿ)               |

---

