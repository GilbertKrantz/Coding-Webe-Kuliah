using System.ComponentModel.DataAnnotations;
using System.Diagnostics.CodeAnalysis;

namespace WareHouseAPI.Model
{
    public class Users
    {
        [NotNull]
        [Key]
        public Guid UserId { get; set; }

        [MaxLength(255)]
        [NotNull]
        public string Email { get; set; }

        [MaxLength(255)]
        [NotNull]
        public string Password { get; set; }

        [MaxLength(255)]
        [NotNull]
        public string Name { get; set; }
    }
}
