def maxHeight(height, width, length, n):
    # Code here
    def form_boxes(height, width, length, n):
        boxes = []
        for i in range(n):
            boxes.append((height[i], width[i], length[i]))

        return boxes

    def get_all_rotations_of_box(box):
        return [(box[1], box[2], box[0]),
                box,
                (box[2], box[0], box[1])]

    def gen_all_instances_boxes(boxes):
        rotated_boxes = []
        for box in boxes:
            rotated_boxes += get_all_rotations_of_box(box)

        return rotated_boxes

    def get_sorted_boxes(boxes):
        print(boxes)
        cmp = lambda x: x[1] * x[2]
        boxes.sort(key=cmp, reverse=True)

        return boxes

    def get_height_by_LIS(boxes):
        n = len(boxes)
        LIS = [box[0] for box in boxes]
        for i in range(n - 1, -1, -1):
            for j in range(i + 1, n):
                # add the height of current box only if
                # dimensions are strictly increasing
                # also you can rotate the 2d base of the box
                # so either rotation can be in strictly increasing mode
                if (boxes[i][1] > boxes[j][1] and boxes[i][2] > boxes[j][2]) or \
                        (boxes[i][1] > boxes[j][2] and boxes[i][2] > boxes[j][1]):
                    LIS[i] = max(boxes[i][0] + LIS[j], LIS[i])

        return max(LIS)

    # the main tasks here
    boxes = form_boxes(height, width, length, n)
    # print(f'formed_boxes = {boxes}')
    boxes = gen_all_instances_boxes(boxes)
    # print(f'instancews = {boxes}')
    sorted_boxes = get_sorted_boxes(boxes)
    print(f'sorted= boxe = {sorted_boxes}')
    return get_height_by_LIS(sorted_boxes)


# testcase 1
n = int(input())
height = list(map(int, input().split()))
width = list(map(int, input().split()))
length = list(map(int, input().split()))
print(maxHeight(height, width, length, n))
