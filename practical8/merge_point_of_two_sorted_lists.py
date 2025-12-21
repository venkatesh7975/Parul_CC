class Node:
    def __init__(self, x):
        self.data = x
        self.next = None


def build_list(node_map):
    values = list(map(int, input().split()))
    head = None
    tail = None

    for x in values:
        if x == -1:
            break

        if x in node_map:
            new_node = node_map[x]
        else:
            new_node = Node(x)
            node_map[x] = new_node

        if head is None:
            head = tail = new_node
        else:
            tail.next = new_node
            tail = new_node

    return head


def get_length(head):
    length = 0
    while head:
        length += 1
        head = head.next
    return length


def find_merge_point(a, b):
    len1 = get_length(a)
    len2 = get_length(b)

    diff = abs(len1 - len2)

    if len1 > len2:
        while diff > 0:
            a = a.next
            diff -= 1
    else:
        while diff > 0:
            b = b.next
            diff -= 1

    while a and b:
        if a is b:          # IMPORTANT: reference comparison
            return a.data
        a = a.next
        b = b.next

    return -1


# -------- MAIN --------
node_map = {}

head1 = build_list(node_map)
head2 = build_list(node_map)

print(find_merge_point(head1, head2))