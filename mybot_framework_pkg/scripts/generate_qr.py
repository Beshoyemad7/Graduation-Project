import qrcode
from PIL import Image


base_url = "http://192.168.1.3:5000/?token=my_secure_token_1234"

qr = qrcode.QRCode(
    version=5,  
    error_correction=qrcode.constants.ERROR_CORRECT_H,  
    box_size=10,
    border=5
)
qr.add_data(base_url)
qr.make(fit=True)

qr_img = qr.make_image(fill="black", back_color="white").convert("RGB")

icon_path = "robot_icon.png"  
icon = Image.open(icon_path)

if icon.mode in ("RGBA", "P"):
    icon = icon.convert("RGB")

qr_width, qr_height = qr_img.size
icon_size = qr_width // 7  
icon = icon.resize((icon_size, icon_size), Image.LANCZOS)

icon_x = (qr_width - icon_size) // 2
icon_y = (qr_height - icon_size) // 2

qr_img.paste(icon, (icon_x, icon_y))

qr_img.save("qrcode_with_icon.png")

print(" QR Code Done ✅ ")
