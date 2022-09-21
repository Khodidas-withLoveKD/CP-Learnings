from heapq import heappush, heappop


class PriorityQueue:
    def __init__(self):
        self.Heap = []

    def enqueue_with_priority(self, priority, value):
        heappush(self.Heap, (priority, value))

    def deque(self):
        return heappop(self.Heap)[1]


# priorities
CRITICAL = -3
IMPORTANT = -2
NEUTRAL = -1
pq = PriorityQueue()
pq.enqueue_with_priority(IMPORTANT, "Windshield wipers turned on")
# pq.enqueue_with_priority("Windshield wipers turned on", IMPORTANT)
pq.enqueue_with_priority(NEUTRAL, "Radio station tuned in")
# pq.enqueue_with_priority("Radio station tuned in", NEUTRAL)
pq.enqueue_with_priority(CRITICAL, "Brake pedal depressed")
# pq.enqueue_with_priority("Brake pedal depressed", CRITICAL)
pq.enqueue_with_priority(IMPORTANT, "Hazard lights turned on")
# pq.enqueue_with_priority("Hazard lights turned on", IMPORTANT)

print(pq.deque())
print(pq.deque())
print(pq.deque())
print(pq.deque())

