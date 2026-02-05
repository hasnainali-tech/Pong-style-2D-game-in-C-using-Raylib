class Paddle
{
private:
  int width;
  int height;
  int speedY;

protected:
  float x;
  float y;

public:
  Paddle();
  void Update();
  void Draw() const;
  void setxy(int a, int b, int screenWidth, int screenHeight);
  int getwidth();
  int getheight();
  int getX();
  int getY();
  int score;
};

class comp : public Paddle
{
public:
  void update(int ball_y, int ball_x);
};
