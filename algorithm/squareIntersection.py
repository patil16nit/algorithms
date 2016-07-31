def find_range(p1,l1,p2,l2):
    #find max of the 2 points
    highest_start_point = max(p1,p2)
    #find min with widths
    lowest_end_point=min(p1+l1, p2+l2)
    if highest_start_point >= lowest_end_point:
        return (None, None)
    overlap_length = lowest_end_point - highest_start_point
    return (highest_start_point, overlap_length)

def find_intersection(rect1,  rect2):
    x_overlap_point, width = find_range(rect1['left_x'],rect1['width'],rect2['left_x'],rect2['width'])
    y_overlap_point, height = find_range(rect1['lower_y'],rect1['height'],rect2['lower_y'],rect2['height'])
    if not width or not height:
        return {
            'left_x': None,
            'bottom_y': None,
            'width': None,
            'height': None,
        }
    else:
        return {
            'left_x': x_overlap_point,
            'bottom_y': y_overlap_point,
            'width': width,
            'height': height,
        }

def main():
    rect1 = {'left_x': 3,'width':10, 'lower_y':4, 'height':5}
    rect2 = {'left_x': 8,'width':10, 'lower_y':8, 'height':13}
    print(find_intersection(rect1,rect2))


if __name__:
    import cProfile
    cProfile.run("main()")
