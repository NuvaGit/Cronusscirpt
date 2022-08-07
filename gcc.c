

const int8 PolarArray[] = { -100,-100,-100,-100,-100,-100,-100,-100,-100,-99,-99,-99,-98,-98,-98,-97,-97,-96,-96,-95,-94,-94,-93,-93,-92,-91,-90,-90,-89,-88,-87,-86,-85,-84,-83,-82,-81,-80,-79,-78,-77,-76,-75,-74,-72,-71,-70,-69,-67,-66,-65,-63,-62,-61,-59,-58,-56,-55,-53,-52,-50,-49,-47,-46,-44,-43,-41,-40,-38,-36,-35,-33,-31,-30,-28,-26,-25,-23,-21,-20,-18,-16,-14,-13,-11,-9,-7,-6,-4,-2,0,2,4,6,7,9,11,13,14,16,18,20,21,23,25,26,28,30,31,33,35,36,38,40,41,43,44,46,47,49,51,52,54,55,56,58,59,61,62,63,65,66,67,69,70,70,72,73,74,75,77,78,79,80,81,82,83,84,85,86,87,88,89,89,90,91,92,92,93,94,94,95,95,96,97,97,97,98,98,99,99,99,99,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,99,99,99,99,98,98,97,97,97,96,95,95,94,94,93,92,92,91,90,89,89,88,87,86,85,84,83,82,81,80,79,78,77,75,74,73,72,71,70,69,67,66,65,63,62,61,59,58,56,55,53,52,50,49,47,46,44,43,41,40,38,36,35,33,31,30,28,26,25,23,21,20,18,16,14,13,11,9,7,6,4,2,0,-1,-3,-5,-7,-8,-10,-12,-13,-15,-17,-19,-20,-22,-24,-25,-27,-29,-30,-32,-34,-35,-37,-39,-40,-42,-43,-45,-46,-48,-50,-51,-53,-54,-55,-57,-58,-60,-61,-62,-64,-65,-66,-68,-69,-70,-71,-73,-74,-75,-76,-77,-78,-79,-80,-81,-82,-83,-84,-85,-86,-87,-88,-89,-89,-90,-91,-92,-92,-93,-93,-94,-95,-95,-96,-96,-97,-97,-97,-98,-98,-99,-99,-99,-99,-100,-100,-100,-100,-100};
const int8 LinearArray[] = { 100,-100,-99,-98,-97,-96,-95,-94,-93,-91,-90,-89,-88,-87,-86,-85,-84,-82,-81,-80,-79,-78,-77,-76,-75,-73,-72,-71,-70,-69,-68,-67,-66,-64,-63,-62,-61,-60,-59,-58,-57,-55,-54,-53,-52,-51,-50,-49,-48,-46,-45,-44,-43,-42,-41,-40,-39,-37,-36,-35,-34,-33,-32,-31,-30,-28,-27,-26,-25,-24,-23,-22,-21,-19,-18,-17,-16,-15,-14,-13,-12,-10,-9,-8,-7,-6,-5,-4,-3,-11,2,3,4,5,6,7,8,10,11,12,13,14,15,16,17,19,20,21,22,23,24,25,26,28,29,30,31,32,33,34,35,37,38,39,40,41,42,43,44,46,47,48,49,50,51,52,53,55,56,57,58,59,60,61,62,64,65,66,67,68,69,70,71,73,74,75,76,77,78,79,80,82,83,84,85,86,87,88,89,91,92,93,94,95,96,97,98,100,100,100,99,98,97,96,95,94,93,91,90,89,88,87,86,85,84,82,81,80,79,78,77,76,75,73,72,71,70,69,68,67,66,64,63,62,61,60,59,58,57,55,54,53,52,51,50,49,48,46,45,44,43,42,41,40,39,37,36,35,34,33,32,31,30,28,27,26,25,24,23,22,21,19,18,17,16,15,14,13,12,10,9,8,7,6,5,4,3,1,-1,-1,-2,-3,-4,-5,-6,-7,-8,-10,-11,-12,-13,-14,-15,-16,-17,-19,-20,-21,-22,-23,-24,-25,-26,-28,-29,-30,-31,-32,-33,-34,-35,-37,-38,-39,-40,-41,-42,-43,-44,-46,-47,-48,-49,-50,-51,-52,-53,-55,-56,-57,-58,-59,-60,-61,-62,-64,-65,-66,-67,-68,-69,-70,-71,-73,-74,-75,-76,-77,-78,-79,-80,-82,-83,-84,-85,-86,-87,-88,-89,-91,-92,-93,-94,-95,-96,-97,-98,-100};


define Fire = PS4_R2;
define Ads  = PS4_L2;


int ToggleTaylorPolarAim = TRUE;


int ToggleAAType         =    100; // Polar Curve 0 / Square Curve 1 \\


int NuvaAim         =    5;

             0                 Circular                  Diamond
             1                 Tall Oval                 Tall Diamond
             2                 Wide Oval                 Wide Diamond
             3                 Vortex Oval               Spiral Prism
             4                 Spiral                    Spiral Diamond
             5                 Helix                     Helix Diamond

*/

int ToggleADirection     = FALSE; // Reverses the Shape Direction
int TaylorRadius         =    1; // Size of the shape
int AdsSpeed             =    1; // Speed of the shape when NOT moving Right Stick
int TaylorAngle          =    1; // Speed of the shape when moving right stick

// boost fire using RUMBLE

int ToggleBoostFire      = FALSE; // If you want Boost in strength when you Fire
define BattStickyPower = 10000;
define BattStickyWait  = 10000;
/*=== V a r i a b l e s ===*/

int RX,RY,angle,CosAngle,SinAngle,ActualMagnitude,MaxMagnitude,GetAngle,InSpiral,OutSpiral,i,inc,x,y;
int PolarStrength,SmartAAV1Rumble,SpiralPosition1,InnerSpiral,OuterSpiral,SpiralPosition2,Position,Angledegree;
define False              = FALSE;
define True               = TRUE;

// dont touch
int CycleRefresh;
define TimeInterval = 4;

init {
/* This is needed for several shapes */
	InitializeShapeChange();
}

main {

	if(ToggleTaylorPolarAim)
	{

		RX = get_val(PS4_RX);
		RY = get_val(PS4_RY);
		ActualMagnitude = isqrt(pow(RX, 2) + pow(RY, 2));
		MaxMagnitude = (ActualMagnitude < 100);
		angle = angle % 360;

		// Angle Direction \\
		if(ToggleADirection) {
			Angledegree = (get_val(PS4_RX) > 0);
		}
		// Selected Curve Type \\
		if(ToggleAAType == 0){
		CosAngle = PolarArray[(angle + 270) % 360];
		SinAngle = PolarArray[angle % 360];
	    }
	    if(ToggleAAType == 1){
	    CosAngle = LinearArray[(angle + 270) % 360];
		SinAngle = LinearArray[angle % 360];
		}

        if ((abs(get_val(PS4_RX)) < 10) * (abs(get_val(PS4_RY)) < 10))
	    	angle += AdsSpeed + GetAngle;
	    else
	    	angle += TaylorAngle + GetAngle;

		if(ToggleBoostFire)
		{
			if(get_ival(Fire))
			{
				SmartAAV1Rumble = get_rumble(RumbleToUse());


		        if(SmartAAV1Rumble > 10 && SmartAAV1Rumble < 90)
		        {

				    SmartAAV1Rumble = 0;
			    }
			    if(!get_rumble(RUMBLE_A) && !get_rumble(RUMBLE_B))
			    {

			    }
			    else
			    {
					GetShapes(PolarStrength/2);
		    	}
		    }
		    if(event_release(Fire))
			{
				GetAngle = 0;
			}
		}
		if(get_val(Ads) || get_val(Fire))
		{
        	if(ActualMagnitude < TaylorRadius)
        	{
	   			SinAngle -= RX;
				CosAngle -= RY;
			}
			else
			{
				SinAngle = (SinAngle * (200 - ((abs(RY) + ActualMagnitude) / 10) * 10) / 200) * MaxMagnitude;
				CosAngle = (CosAngle * (200 - ((abs(RX) + ActualMagnitude) / 10) * 10) / 200) * MaxMagnitude;
			}
			if(!ToggleBoostFire || !get_rumble(RumbleToUse())){

				GetShapes(TaylorRadius);
			}
	    	PolarStrength = 0;
	        SmartAAV1Rumble   = 0;
   		 }
	}
}
function GetShapes(f_var){

	if(NuvaAim == 0)
    {
		if(Angledegree){
	   	 	offset(PS4_RX,(f_var * SinAngle)/ 100);
        	offset(PS4_RY,(f_var * CosAngle) /100);
   	 	}else{
        	offset(PS4_RY ,(f_var * SinAngle)/100);
        	offset(PS4_RX ,(f_var * CosAngle)/100);
    	}
    }
    if(NuvaAim == 1) // Tall Oval
    {

		if(Angledegree){
    		offset(PS4_RX,(f_var/2 * SinAngle)/ 100);
        	offset(PS4_RY,(f_var  * CosAngle) /100);
    	}else{
    		offset(PS4_RY,(f_var * SinAngle)/100);
    		offset(PS4_RX,(f_var/2 * CosAngle)/ 100);
    	}
    }
    if(NuvaAim == 2) // Wide Oval
    {
    	if(Angledegree){
        	offset(PS4_RX,(f_var * SinAngle)/ 100);
        	offset(PS4_RY,(f_var/2 * CosAngle) /100);
        }else{
        	offset(PS4_RX,(f_var * CosAngle)/ 100);
       		offset(PS4_RY,(f_var/2 * SinAngle) /100);
        }
    }
    if(NuvaAim == 3) // SpiralOval
	{
		if(!(CycleRefresh++ % TimeInterval))
		{
			if(!SpiralPosition1)
			{
				InnerSpiral -= 1;
				if(InnerSpiral < f_var/2)
					SpiralPosition1 = True;
			}
			else
			{
			    InnerSpiral += 1;
				if(InnerSpiral > f_var)
					SpiralPosition1 = False;
			}
			if(!SpiralPosition2)
			{
				OuterSpiral -= 1;
				if(OuterSpiral < f_var/2)
					SpiralPosition2 = True;
			}
			else
			{
				OuterSpiral += 1;
				if(OuterSpiral >  f_var)
					SpiralPosition2 = False;
			}
			CycleRefresh = 0;
		}

		if(Angledegree){
        	offset(PS4_RX,(OuterSpiral * SinAngle)/ 100);
        	offset(PS4_RY,(InnerSpiral * CosAngle)/100);
        }else{
        	offset(PS4_RX,(OuterSpiral * CosAngle)/ 100);
        	offset(PS4_RY,(InnerSpiral * SinAngle)/100);
        }
    }
    if(NuvaAim == 4) // Spiral
	{

		if(!(CycleRefresh++ % TimeInterval))
		{
			if(!SpiralPosition1)
			{
				InSpiral -= 1;
				if(InSpiral < f_var/2)
					SpiralPosition1 = True;
			}
			else
			{
			    InSpiral += 1;
				if(InSpiral > f_var)
					SpiralPosition1 = False;
			}
			if(!SpiralPosition2)
			{
				OutSpiral -= 1;
				if(OutSpiral < f_var/2)
					SpiralPosition2 = True;
			}
			else
			{
				OutSpiral += 1;
				if(OutSpiral >  f_var)
					SpiralPosition2 = False;
			}
			CycleRefresh = 0;
		}
		if(Angledegree){
        	offset(PS4_RX,(OutSpiral * SinAngle)/ 100);
        	offset(PS4_RY,(InSpiral * CosAngle)/100);
        }else{
        	offset(PS4_RX,(OutSpiral * CosAngle)/ 100);
        	offset(PS4_RY,(InSpiral * SinAngle)/100);
        }
    }
    if(NuvaAim == 5) // Helix
	{
		inc = (i % 100);
	    if(Position == 0){
	   		x = inc; y = 100 - inc;}
	    else if (Position == 1){
	    	x = 100 - inc; y = - inc;}
	    else if (Position == 2){
	    	x = -inc; y = -100 + inc;}
	    else if(Position == 3){
	    	x = -100 + inc; y = inc;}
	    Position ++;

	    if(Position == 4){
	    	Position = 0;
	    }
	 	offset(PS4_RX,(f_var * x)/100);
        offset(PS4_RY,(f_var * y)/100);
    }
}
function InitializeShapeChange() {
	if(NuvaAim == 3) {
		InnerSpiral = TaylorRadius/2;
		OuterSpiral = TaylorRadius;
	}
}
function RumbleToUse() {
    if(get_rumble(RUMBLE_A) == get_rumble(RUMBLE_B))
    {
        return RUMBLE_A;
    }
    if(get_rumble(RUMBLE_A) == 100)
    {
    	return RUMBLE_B;
	}
	if(get_rumble(RUMBLE_B) == 100)
	{
    	return RUMBLE_A;
	}
    if(get_rumble(RUMBLE_A) > get_rumble(RUMBLE_B))
    {
        return RUMBLE_A;
    }
    if(get_rumble(RUMBLE_A) < get_rumble(RUMBLE_B))
    {
        return RUMBLE_B;
    }
    return 0;
}
function offset( axis,  offset_val) {
  set_val(axis, clamp(offset_val * (100 - abs(get_val(axis))) / 100 + get_val(axis), -100, 100));
  return;
}
