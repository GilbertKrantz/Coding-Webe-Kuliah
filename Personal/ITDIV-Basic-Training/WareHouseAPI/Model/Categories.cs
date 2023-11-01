using System.ComponentModel.DataAnnotations;
using System.ComponentModel.DataAnnotations.Schema;
using System.Diagnostics.CodeAnalysis;

namespace WareHouseAPI.Model
{
    public class Categories
    {
        [NotNull]
        [ForeignKey("UserId")]
        public Guid UserId { get; set; }

        [Key]
        [NotNull]
        public int CategoryId { get; set; }

        [MaxLength(255)]
        [NotNull]
        public string CategoryName { get; set; }
    }
}
