import Converters
from Converters import kgs_to_lbs
# importing from a different package
import ecommerce.shipping
# OR
from ecommerce.shipping import calc_shipping_cost

print(Converters.lbs_to_kg(200))
print(kgs_to_lbs(40))

ecommerce.shipping.calc_shipping_cost()
calc_shipping_cost()

