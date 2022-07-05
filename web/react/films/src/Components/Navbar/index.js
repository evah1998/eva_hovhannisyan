import React from "react";
import { Nav, NavLink, NavMenu } 
  from "./NavbarElements";
  
const Navbar = () => {
  return (
    <>
      <Nav>
        <NavMenu>
          <NavLink to="/home" activeStyle>
            Home
          </NavLink>
          <NavLink to="/films" activeStyle>
            Films
          </NavLink>
        </NavMenu>
      </Nav>
    </>
  );
};
  
export default Navbar;