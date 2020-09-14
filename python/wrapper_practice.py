def another_wrapping(style):
    def add_wrapping(item):
        def wrapped_item():
            return f'{style} {str(item())} is warpped!'
        return wrapped_item
    return add_wrapping

@another_wrapping('horrible')
def bike():
    return 'my bike'

print(bike())
