from PIL import Image

image = Image.open("test_map.png")
image_out = image.convert("RGB")

map_txt = open("test_map.txt", "a")

# Clear file before writing
map_txt.seek(0)
map_txt.truncate()

for y in range(image_out.width):
    for x in range(image_out.height):
        if image_out.getpixel((x, y)) == (0, 0, 0):  # Wall
            map_txt.write("1 ")
        elif image_out.getpixel((x, y)) == (255, 255, 255):  # Floor
            map_txt.write("0 ")
        elif image_out.getpixel((x, y)) == (50, 0, 0):  # Box
            map_txt.write("2 ")
        elif image_out.getpixel((x, y)) == (170, 0, 139):  # StaticDanger
            map_txt.write("3 ")
        elif image_out.getpixel((x, y)) == (0, 255, 0):  # Player
            map_txt.write("9 ")
    map_txt.write("\n")

image.close()
map_txt.close()

print("Map correctly converted from PNG to TXT \n")

