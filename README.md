# Subdivision Surfaces
## Author: Ziheng Ge
-- This is a 3D program for surface subdivision. Import control mesh from obj file, and select one subdivision scheme (Loop, Catull-Clark or Doo-Sabin), then you can get smooth spline surfaces after several iterations.
-- You can also export the refined surfaces as obj files.
-- Loop's scheme only works for triangle meshes, while Catmull-Clark and Doo-Sabin can deal with arbitrary meshes. However, they always cause high distortion on triangle meshes, so we'd better use Loop.