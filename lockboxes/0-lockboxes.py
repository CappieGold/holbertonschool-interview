#!/usr/bin/python3
def canUnlockAll(boxes):
    """
    Determines if all boxes can be opened.

    boxes is a list of lists:
      - boxes[i] contains the keys found in box i
      - The first box (boxes[0]) is already unlocked
    A key with the same number as a box opens that box.

    Returns True if all boxes can be opened, else returns False.
    """
    unlocked = {0}
    stack = [0]

    while stack:
        current_box = stack.pop()
        # Pour chaque clé trouvée dans la boîte courante
        for key in boxes[current_box]:
            # On vérifie que la clé correspond à une boîte existante
            # et pas encore ouverte.
            if key < len(boxes) and key not in unlocked:
                unlocked.add(key)
                stack.append(key)

    # Si le nombre de boîtes déverrouillées est égal au nombre total de boîtes,
    # alors toutes les boîtes peuvent être ouvertes.
    return len(unlocked) == len(boxes)
