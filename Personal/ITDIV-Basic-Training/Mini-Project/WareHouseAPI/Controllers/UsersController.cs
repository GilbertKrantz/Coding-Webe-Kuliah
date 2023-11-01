// using Microsoft.AspNetCore.Components;
using Microsoft.AspNetCore.Cors;
using Microsoft.AspNetCore.Mvc;
using Microsoft.EntityFrameworkCore;
using WareHouseAPI.Data;
using WareHouseAPI.Model;
using WareHouseAPI.Model.Requests;
using WareHouseAPI.Model.Results;

// For more information on enabling Web API for empty projects, visit https://go.microsoft.com/fwlink/?LinkID=397860

namespace WareHouseAPI.Controllers
{
    [Route("api/[controller]")]
    [ApiController]
    public class UsersController : ControllerBase
    {
        private readonly AppDbContext _context;

        public UsersController(AppDbContext context)
        {
            _context = context;
        }

        // GET: api/<UserController>/GetCategories
        [HttpGet]
        [Route("GetCategories")]
        public List<Categories> Get()
        {
            var CategoriesList = _context.Categories
                .Select(x => new Categories
                {
                    CategoryId = x.CategoryId,
                    CategoryName = x.CategoryName,
                });
            return CategoriesList.ToList();
        }

        // GET api/<UserController>/5
        [HttpGet("{id}")]
        public string Get(Guid id)
        {
            return "value";
        }

        // POST api/<UserController>/Registration
        [HttpPost]
        [EnableCors("AllowAll")]
        [Route("Registration")]
        
        public async Task<ActionResult<Users>> Post([FromBody] CreateUsersRequest request)
        {
            if (!ModelState.IsValid)
            {
                return BadRequest(ModelState);
            }

            var checkSameEmail = await _context.Users.FirstOrDefaultAsync(x => x.Email == request.Email);
            if (checkSameEmail != null)
            {
                return BadRequest("Email already exists");
            }

            var Users = new Users
            {
                UserId = Guid.NewGuid(),
                Email = request.Email,
                Password = request.Password,
                Name = request.Name
            };
            _context.Users.Add(Users);
            await _context.SaveChangesAsync();
            return CreatedAtAction(nameof(Get), new { UserId = Users.UserId }, Users);
        }

        // POST api/<UserController>/Login
        [HttpPost]
        [Route("Login")]
        public async Task<ActionResult<Users>> Login([FromBody] LoginUserRequest request)
        {
            if (!ModelState.IsValid)
            {
                return BadRequest(ModelState);
            }

            var Users = await _context.Users.FirstOrDefaultAsync(x => x.Email == request.Email && x.Password == request.Password);
            if (Users == null)
            {
                return NotFound();
            }

            return Ok(Users);
        }

        // POST api/<UserController>/NewCategory
        [HttpPost]
        [Route("NewCategory")]
        [EnableCors]
        public ActionResult PostAddCategory([FromBody] NewCategoryRequest newCategory)
        {
            if (!ModelState.IsValid)
            {
                return BadRequest(ModelState);
            }
            if (_context.Categories.Any(x => x.CategoryName == newCategory.CategoryName))
            {
                return NotFound("Category Already Exist");
            }

            var category = new Categories
            {
                UserId = newCategory.UserId,
                CategoryName = newCategory.CategoryName
            };

            _context.Categories.Add(category);
            _context.SaveChanges();

            return Ok();
        }

        // PUT api/<UserController>/5
        [HttpPut("{id}")]
        public async Task<ActionResult<Users>> Put(Guid id, [FromBody] CreateUsersRequest UpdateUsersRequest)
        {
            if (!ModelState.IsValid)
            {
                return BadRequest(ModelState);
            }

            var Users = await _context.Users.FirstOrDefaultAsync(x => x.UserId == id);
            if (Users == null)
            {
                return NotFound();
            }

            Users.Email = UpdateUsersRequest.Email;
            Users.Password = UpdateUsersRequest.Password;
            Users.Name = UpdateUsersRequest.Name;

            await _context.SaveChangesAsync();

            return Ok();
        }

        // PUT api/<UserController>/PutCategory/5
        [HttpPut]
        [Route("PutCategory/{id}")]
        public async Task<ActionResult<Categories>> PutCategory(int id, [FromBody] UpdateCategoryRequest updateCategory)
        {
            if (!ModelState.IsValid)
            {
                return BadRequest(ModelState);
            }

            var category = await _context.Categories.FirstOrDefaultAsync(x => x.CategoryId == id);
            if (category == null)
            {
                return NotFound();
            }

            category.CategoryName = updateCategory.CategoryName;

            await _context.SaveChangesAsync();

            return Ok();
        }

        // DELETE api/<UserController>/5
        [HttpDelete("{id}")]
        public async Task<ActionResult<Users>> Delete(Guid id)
        {
            var Users = await _context.Users.FirstOrDefaultAsync(x => x.UserId == id);
            if (Users == null)
            {
                return NotFound();
            }

            _context.Users.Remove(Users);
            await _context.SaveChangesAsync();

            return Ok();
        }

        // DELETE api/<UserController>/DeleteCategory/5
        [HttpDelete]
        [Route("DeleteCategory/{id}")]
        public async Task<ActionResult<Categories>> DeleteCategory(int id)
        {
            var category = await _context.Categories.FirstOrDefaultAsync(x => x.CategoryId == id);
            if (category == null)
            {
                return NotFound();
            }

            _context.Categories.Remove(category);
            await _context.SaveChangesAsync();

            return Ok();
        }
    }
}
