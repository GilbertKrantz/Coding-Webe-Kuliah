using Microsoft.AspNetCore.Identity;

namespace WareHouseT2.Data
{
    public class ApplicationUser : IdentityUser
    {
        public string Name { get; set; }
    }
}
